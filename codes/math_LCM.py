def GCD (a, b):
	if b == 0:
		return a
	else:
		return GCD(b, a%b)

def LCM (a, b):
	return (a*b) / GCD(abs(a),abs(b))

a, b = input(), input()
print (LCM(a,b))
