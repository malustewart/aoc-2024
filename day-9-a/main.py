def parse_file(filename, disk):
    with open(filename, 'r') as file:
        for line in file:
            for c in line:
                disk.append(int(c))


filename = 'day-9-a/input'  # Replace with the path to your file
diskzip = []
parse_file(filename, diskzip)

disk = []

for i,l in enumerate(diskzip):
    for j in range(l):
        if i%2:
            disk.append(-1)
        else:
            disk.append(i//2)
start = 0
end = len(disk)-1

while start < end:
    while disk[start] != -1 and start < end:
        start+=1
    while disk[end] == -1 and start < end:
        end -=1
    while disk[start] == -1 and disk[end] != -1 and start < end:
        disk[start] = disk[end]
        disk[end] = -1
        start+=1
        end-=1

result = 0
for i,block in enumerate(disk):
    if block == -1: 
        break
    result += i*block

print(result)