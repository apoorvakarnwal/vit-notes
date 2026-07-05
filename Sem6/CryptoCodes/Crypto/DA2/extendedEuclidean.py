#Name- Niyati Kumaria
#Reg no-22BCE2017

def extended_euclidean(a, b):
    if b == 0:
        return 1, 0, a
    else:
        s1, t1, d = extended_euclidean(b, a % b)
        s = t1
        t = s1 - (a // b) * t1
        return s, t, d

# Example usage
a = int(input("Enter value for a: "))
b = int(input("Enter value for b: "))
s, t, d = extended_euclidean(a, b)
print(f"s: {s}, t: {t}, d: {d}")
