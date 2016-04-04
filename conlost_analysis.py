f=open("network_health.txt", "r")
lines=f.readlines()
consecutive_lost=0
consecutive_lost_max=0

consecutive_lost_array=[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

for line in lines:
	token=line.split()
	if int(token[0]) == 0:
		consecutive_lost +=1
	elif int(token[0]) == 1:
		consecutive_lost_array[consecutive_lost-1] += 1
		if consecutive_lost > consecutive_lost_max:
			consecutive_lost_max = consecutive_lost
		consecutive_lost=0

print consecutive_lost_array



