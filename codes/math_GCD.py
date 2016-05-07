def GCD (a, b):
	if b == 0:
		return a
	else:
		return GCD(b, a%b)	

a = input ()
b = input ()

if (abs(a) > abs(b)):
	print (GCD(abs(a),abs(b)))
else:
	print (GCD(abs(b),abs(a)))
