
def calcul(argu, argd, argt):
	return argu - argd * argt


def lol():
	total = 0
	i = 0;
	while i < 2000000:
		total += calcul(5, 45, 8)
		i += 1
	print total

lol()