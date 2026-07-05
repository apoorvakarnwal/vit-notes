import requests
import re
import xmltodict
# Assuming self and other variables are defined in the broader context where this code runs
# For demonstration, I'll define some mock variables.
class MockSelf:
    def parse_registry_file(self, reg_path):
        # This is a mock implementation. Replace with your actual parser.
        # It should return a dictionary where keys are paths and values are the string values.
        return {
            "MCDB\\5300\\Machine\\Extension DLLs\\TF\\Load Extension": "1.1",
            "MCDB\\5300\\ResultViewer\\Extension DLLs\\TF\\Load Extension": "False",
        }
    versionModified = "1.2.3"
    total_tooltypes = {"old_id_val": "BASE_TOOLTYPE_UPPER_MOCK"} # Mock for 'self.total_tooltypes'

self = MockSelf()
new_tt_name = "SpectracShape22"
base_tooltype_upper = "BASE_TOOLTYPE_UPPER_MOCK" # Mock variable
token = "your_auth_token" # Mock variable
xml_url = ["http://example.com/mock_mcdb_file.xml"] # Mock URL for demonstration

# --- Start of your provided code (modified with mock values for demonstration) ---
for url in xml_url:
    mock_xml_content = """
    
    """
    # For a real scenario:
    # response = requests.get(url, headers={'Authorization': f"Token {token}"}, verify=False)
    # data = response.content.decode("utf-8")
    data = mock_xml_content # Using mock data for demonstration

    xml_name = url.split('/')[-1]
    base_tt_locs = [_.start() for _ in re.finditer(rf'({base_tooltype_upper})', data)]

    new_data = ""
    prev, l, r = 0, 0, 0

    for base_tt_loc in base_tt_locs:
        l = data[:base_tt_loc].rfind('<')
        r = data[base_tt_loc:].find('/>') + base_tt_loc + len('/>')

        while l >= 0:
            if data[l] == '\n':
                break
            else:
                l -= 1

        if data[l:].find("Keyoptions") != -1:
            r = data[r:].find('>') + r + len('>')

        section = data[l:r].replace(base_tooltype_upper, new_tt_name)

        if "Code" in section:
            # Mocking self.total_tooltypes and new_id
            idx = list(self.total_tooltypes.values()).index(base_tooltype_upper)
            old_id = list(self.total_tooltypes.keys())[idx]
            new_id = "new_id_val" # Mock variable
            section = section.replace(old_id, new_id)

        if "VersionModified" in section:
            correct_version = self.versionModified
            major_version = correct_version.split('.')[0]
            if len(major_version) == 1:
                correct_version = f'0{correct_version}'
            section = re.sub(r'VersionModified="([0-9.]+)"',
                             f'VersionModified="{correct_version}"', section)

        new_data += data[prev:l] + section
        prev = r

    new_data += data[prev:]
    parsed = xmltodict.parse(new_data)

    reg_path = "./TF_EnableTF_temp_del.reg"
    reg_dict = self.parse_registry_file(reg_path)

    # --- Start of the code to be added ---
    for reg_full_path, reg_value in reg_dict.items():
        # Split the registry path into components, skipping 'MCDB' and 'Value'
        # Example: "MCDB\5300\Machine\Extension DLLs\TF\Load Extension"
        path_components = reg_full_path.replace("MCDB\\", "").split('\\')
        # The last component is the KeyName to be updated (e.g., "Load Extension")
        target_key_name_in_xml = path_components[-1]
        # The path to navigate through the XML hierarchy
        xml_nav_path = path_components[:-1]

        current_level = parsed['MCDb'] # Start from the root 'MCDb'

        path_exists = True
        for component in xml_nav_path:
            if isinstance(current_level, dict) and 'Key' in current_level:
                keys = current_level['Key']
                if not isinstance(keys, list):
                    keys = [keys] # Ensure 'keys' is always a list for consistent iteration

                found_component = False
                for key_element in keys:
                    if isinstance(key_element, dict) and key_element.get('@Name') == component:
                        current_level = key_element
                        found_component = True
                        break
                if not found_component:
                    path_exists = False
                    break
            else:
                path_exists = False
                break

        if path_exists:
            # We are now at the level just above the target KeyConfig
            # Find the target Key element that contains the 'KeyConfig' elements.
            # This is specifically looking for where 'Load Extension' is a Key Name.
            # In your XML, 'Load Extension' is a Key itself, and its children are KeyConfig elements.

            target_key_elements = []
            if isinstance(current_level, dict) and 'Key' in current_level:
                if isinstance(current_level['Key'], list):
                    target_key_elements = [k for k in current_level['Key'] if k.get('@Name') == target_key_name_in_xml]
                elif isinstance(current_level['Key'], dict) and current_level['Key'].get('@Name') == target_key_name_in_xml:
                    target_key_elements = [current_level['Key']]
            elif isinstance(current_level, dict) and current_level.get('@Name') == target_key_name_in_xml:
                # If 'Load Extension' itself is the current_level (less common, but good to handle)
                target_key_elements = [current_level]

            for target_key_element in target_key_elements:
                if isinstance(target_key_element, dict) and 'KeyConfig' in target_key_element:
                    key_configs = target_key_element['KeyConfig']
                    if not isinstance(key_configs, list):
                        key_configs = [key_configs] # Ensure it's a list

                    for key_config in key_configs:
                        if isinstance(key_config, dict) and key_config.get('@Name') == new_tt_name:
                            key_config['@Val'] = reg_value
                            print(f"Updated '{reg_full_path}' for '{new_tt_name}' to '{reg_value}'")
                            break # Assuming only one such KeyConfig per Key


    # Convert the modified parsed data back to XML
    modified_xml_data = xmltodict.unparse(parsed, pretty=True)

    # Save the modified XML to the zip file
    # Ensure 'zf' is defined and is a ZipFile object in your actual code
    # zf.writestr(f"MCDB/{xml_name}", modified_xml_data)
    print("\n--- Modified XML Data (Simulated) ---")
    print(modified_xml_data)

# --- End of the code to be added ---