'''
For multiplicative Inverse, we know that, 
If a and b are multiplicative Inverse, then axb congruent to 1 mod n
and, GCD of a and n should must be 1
'''
def HCF(a,n):
    if(n==0):
        return a
    else:
        return HCF(n,a%n)

if __name__ == "__main__":
	# Calculate the multiplicative inverse

	print("Enter the value of the first number")

	a = int(input())

	print("Enter the value of n")

	n = int(input())

	hcf = HCF(a,n)

	if(hcf != 1):
		print("The multiplicative Inverse cannot be found")

	else:
		for i in range (0,n):
			b = i
			res = ((a*b)-1) % n
			if(res == 0):
				print("The multiplicative Inverse is:")
				print(b)