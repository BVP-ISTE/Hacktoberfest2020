#decimal to binary
#find the error in the code
#Enter the Number To be Converted In Binary
num=int(input("Please Enter The Number Which To be Converted In Binary\n"))
i=0
ans=0
while True:
    if num!=0:
       rem=int(num%2)
       ans=ans+(rem*(10**i))
       num=num/2
       i=i+1
    if int(num==0):
       break
print("Binary of the Given no. is:-",ans)
