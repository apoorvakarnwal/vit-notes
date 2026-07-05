def calculate_2d_parity(data):
    rows = len(data)
    cols = len(data[0])
    
    row_parity = [sum(row) % 2 for row in data]
    
    col_parity = [sum(data[row][col] for row in range(rows)) % 2 for col in range(cols)]
    
    overall_parity = sum(row_parity) % 2 ^ sum(col_parity) % 2
    
    for i in range(rows):
        data[i].append(row_parity[i])
    
    col_parity.append(overall_parity)
    data.append(col_parity)
    
    return data

def display_2d_array(array):
    for row in array:
        print(" ".join(map(str, row)))

data = [
    [ 1, 0, 0, 1, 1, 0, 0, 1],
    [ 1, 1, 1, 0, 0, 0, 1, 0],
    [ 0, 0, 1, 0, 0, 1, 0, 0],
    [ 1, 0, 0, 0, 0, 1, 0, 0],
]

print("Original Data:")
display_2d_array(data)

data_with_parity = calculate_2d_parity(data)

print("\nData with Parity:")
display_2d_array(data_with_parity)