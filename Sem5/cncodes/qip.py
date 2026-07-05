TOTAL_ADDRESSES = 256*256*256*256
def allocate_ip_addresses(customers, addresses_per_customer, base_address):
    total_addresses = customers * addresses_per_customer
    start_first_octet = (base_address // (256 ** 3)) % 256
    start_second_octet = (base_address // (256 ** 2)) % 256
    start_third_octet = (base_address // 256) % 256
    start_fourth_octet = base_address % 256
    start_address = f"{start_first_octet}.{start_second_octet}.{start_third_octet}.{start_fourth_octet}"

    last_address = base_address + total_addresses - 1
    end_first_octet = (last_address // (256 ** 3)) % 256
    end_second_octet = (last_address // (256 ** 2)) % 256
    end_third_octet = (last_address // 256) % 256
    end_fourth_octet = last_address % 256
    end_address = f"{end_first_octet}.{end_second_octet}.{end_third_octet}.{end_fourth_octet}"

    base_address += total_addresses
    
    return start_address, end_address, base_address

def main():
    groups = [
        {"customers": 256, "addresses_per_customer": 256},
        {"customers": 256, "addresses_per_customer": 128},
        {"customers": 256, "addresses_per_customer": 256}
    ]
    
    base_address = 190*(256 ** 3)
    b=base_address
    for i, group in enumerate(groups):
        start_address, end_address, base_address = allocate_ip_addresses(
            group["customers"], group["addresses_per_customer"], base_address
        )
        print(f"Group {i+1}:")
        print(f"Starting Address: {start_address}")
        print(f"Ending Address: {end_address}\n")
    
    total_allocated=base_address-b
    print(f"total allocated: {total_allocated}")
    remaining_addresses = TOTAL_ADDRESSES - total_allocated
    print(f"Remaining Addresses: {remaining_addresses}")

if __name__ == "__main__":
    main()