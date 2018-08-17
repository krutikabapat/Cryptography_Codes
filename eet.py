# Extended Euclidien Algorithm
print("Welcome to Euclidien Algorithm\n")

# Enter the value of b
print("Enter the value of b")
b = input()
# Enter the value of n
print("Enter the value of n")
n = input()

def HCF(b,n):
    if(n==0):
        return b
    else:
        return HCF(n,b%n)

hcf = HCF(b,n)

if(hcf != 1):
	print("The multiplicative Inverse cannot be found")


# Initialize the original values
r1 = n
r2 = b
t1 = 0
t2 = 1

while(r2>0):
	q = r1/r2
	r = r1-(q*r2)
	r1 = r2
	r2 = r
	t = t1-(q*t2)
	t1 = t2
	t2 = t

# Check if the value of r1 is 1, if it is 1, then stop
if(r1 == 1):
	b_inverse = t1

# Now calculate the mod of b_inverse and 26
answer = b_inverse%26

# Print the answer
print("The value of multiplicative mod inverse calculation is\n")
print(answer)
