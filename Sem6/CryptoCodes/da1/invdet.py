import numpy as np
from sympy import Matrix

def mod_inverse_det(det, mod):
    """Find the modular inverse of determinant under mod if it exists."""
    for i in range(1, mod):
        if (det * i) % mod == 1:
            return i
    return None  # No modular inverse exists

def mod_matrix_inverse(matrix, mod):
    """Compute the modular inverse of a matrix over Z_mod if it exists."""
    det = int(round(np.linalg.det(matrix))) % mod
    inv_det = mod_inverse_det(det, mod)
    
    if inv_det is None:
        return None  # No inverse exists
    
    adjugate = Matrix(matrix).adjugate()  # Compute adjugate using sympy
    inv_matrix = (inv_det * np.array(adjugate) % mod)  # Apply modular inverse
    
    return inv_matrix

# Define matrices
A = np.array([[5, 0], [3, 1]])
B = np.array([[3, 2], [2, 1]])

# Compute determinant and inverse in Z10
for name, matrix in [('A', A), ('B', B)]:
    det = int(round(np.linalg.det(matrix))) % 10
    inv_matrix = mod_matrix_inverse(matrix, 10)
    
    print(f"Matrix {name}:")
    print(matrix)
    print(f"Determinant (mod 10): {det}")
    if inv_matrix is None:
        print(f"Matrix {name} has no inverse in Z10.\n")
    else:
        print(f"Multiplicative Inverse of {name} (mod 10):\n{inv_matrix}\n")
