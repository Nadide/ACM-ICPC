from itertools import combinations

n,k = map(int, input().split(' '))
c = list(map(int, input().split(' ')))

#c.sort()
coin = []
for i in range(len(c)):
	comb = list(combinations(c,i))
	for j in comb:
		if sum(j) == k:
			for k in j:
				coin.append(k)
coin = set(coin)
print (coin)


