from matplotlib import pyplot as plt

fig, ax = plt.subplots()

f = open("ss.000090.simple", 'rt')
Lines = f.readlines()

x = []
y = []
z = []
Py = []
vy = []
temp = []
for line in Lines:
	nums = line.split()
	if(float(nums[1]) == 64000):
		continue
	x.append(float(nums[1]))
	y.append(float(nums[2]))
	z.append(float(nums[3]))
print (Lines[1])
plt.plot(x, z, linestyle="", marker="o", markersize=1)
# plt.plot(y, x, linestyle="", marker="o", markersize=1)
plt.xlabel("x")
plt.ylabel("z")

#plt.savefig("plot.png")
plt.show()
