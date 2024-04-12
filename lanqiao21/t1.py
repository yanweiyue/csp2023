num_card = [2021 for _ in range(10)]
i = 0
br = False
while not br:
    i+=1
    str_i = str(i)
    num_list = [int(ch) for ch in str_i]
    for n in num_list:
        num_card[n]-=1
        if num_card[n]<0:
            br=True
            break
print(i-1)