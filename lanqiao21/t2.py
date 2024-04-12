# start time:16:02
#判断两点是否共线

x_len = 20
y_len = 21
points = [[x,y] for x in range(x_len) for y in range(y_len)]
kb = set()
for i in range(x_len*y_len):
    x1 = points[i][0]
    y1 = points[i][1]
    for j in range(i+1,x_len*y_len):
        x2 = points[j][0]
        y2 = points[j][1]
        if x1 == x2:
            continue
        else:
            k = (y2-y1)/(x2-x1)
            b = (x2*y1-x1*y2)/(x2-x1)
            kb.add((k,b))
print(len(kb)+20)
                
    
    
