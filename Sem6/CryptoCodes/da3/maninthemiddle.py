
def modExp(base, exp, mod):
    res=1
    while exp>0:
        if(exp%2==1):
            res=(res*base)%mod
        base = (base*base) % mod
        exp//=2
    return res

p=23
g=5
xa=int(input('Alice private key: '))
xb=int(input('Bob private key: '))
xc=int(input('Attacker private key for Alice: '))
xd=int(input('Attacker private key for Bob: '))

ya=modExp(g,xa,p)
yb=modExp(g,xb,p)
yc=modExp(g,xc,p)
yd=modExp(g,xd,p)

yac=modExp(yc,xa,p)
ybd=modExp(yd,xb,p)

print(f"Attacker computes shared key with Alice (KDA): {yac}")
print(f"Attacker computes shared key with Bob (KDB): {ybd}")
