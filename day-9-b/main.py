def parse_file(filename, disk):
    with open(filename, 'r') as file:
        for line in file:
            for c in line:
                disk.append(int(c))


filename = 'day-9-b/input' 
diskzip = []
parse_file(filename, diskzip)

disk = []

for i,l in enumerate(diskzip):
    for j in range(l):
        if i%2:
            disk.append(-1)
        else:
            disk.append(i//2)

end = len(disk)-1

while end > 0:
    while disk[end] == -1 and 0 < end:
        end -=1
        nextend = end
    nextend = end
    file = disk[end]
    while file != -1 and disk[nextend] == file and nextend > 0:
        nextend -= 1
    start = 0
    while start < end:
        while disk[start] != -1 and start <= len(disk):
            start+=1
        nextstart = start
        while nextstart < len(disk) and disk[nextstart] == -1:
            nextstart+=1
        if nextstart - start >= end - nextend and nextstart <= nextend+1:
            while start < nextstart and end > nextend:
                disk[start] = disk[end]
                disk[end] = -1
                start+=1
                end-=1
            break
        
        while  start < len(disk) and disk[start] == -1:
            start += 1
    while end > 0 and disk[end] == file:
        end -= 1


result = 0
for i,block in enumerate(disk):
    if block != -1: 
        result += i*block

print(result)