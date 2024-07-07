N = int(input())
road = [input() for _ in range(N)]

start_lane = -1
min_switches = -1

for i in range(N):
    obstacles = road[i].count("x")
    if road[i][0] == ".":
        if obstacles == 0:
            if start_lane == -1:
                start_lane = i
            if i > start_lane:
                start_lane = i
            switches = i - start_lane
            if min_switches == -1 or switches < min_switches:
                min_switches = switches

if start_lane == -1 and min_switches == -1:
    print(-1)
else:
    print(start_lane + 1)
    print(min_switches)