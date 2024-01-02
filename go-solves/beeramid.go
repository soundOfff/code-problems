package main

func Beeramid(bonus int, price float64) int {
	beers := int(float64(bonus) / price)
	lvls := 0

	for i := 1; i*i <= beers; i++ {
		beers -= i * i
		lvls++
	}

	return lvls
}
