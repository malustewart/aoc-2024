import copy

# File name
file_name = "day-14/input"

# Initialize lists for positions and velocities
positions = []
velocities = []
iterations = 100


# Open the file and process
with open(file_name, "r") as file:
    # Parse the header line separately
    header = file.readline().strip()
    # Perform any specific parsing for the header
    limits = tuple(map(int, header.split()))
    
    # Process the rest of the lines
    for line in file:
        line = line.strip()
        if not line:
            continue  # Skip empty lines
        # Split and parse positions and velocities
        parts = line.split()
        p = tuple(map(int, parts[0][2:].split(',')))
        v = tuple(map(int, parts[1][2:].split(',')))
        positions.append(p)
        velocities.append(v)

nw = 0
ne = 0
se = 0
sw = 0

newpositions = []
middlex = limits[0]//2
middley = limits[1]//2


for pos,vel in zip(positions, velocities):
    newpos = ((pos[0]+iterations*vel[0])%limits[0], (pos[1]+iterations*vel[1])%limits[1])
    if newpos[0] < middlex and newpos[1] < middley:
        nw+=1
    elif newpos[0] < middlex and newpos[1] > middley:
        sw+=1
    elif newpos[0] > middlex and newpos[1] > middley:
        se+=1
    elif newpos[0] > middlex and newpos[1] < middley:
        ne+=1

print(nw*ne*se*sw)


mapabase = []
for i in range(limits[1]):
    mapabase.append(["." for i in range(limits[0])])

for it in range (30000):
    mapa = copy.deepcopy(mapabase)

    for pos,vel in zip(positions, velocities):
        newpos = ((pos[0]+it*vel[0])%limits[0], (pos[1]+it*vel[1])%limits[1])
        mapa[newpos[1]][newpos[0]] = "#"
    
    printt = False;
    for mapline in mapa:
        mapline2 = mapline
        if "##########" in ''.join(mapline2):
            print(it)
