package main

func ProductFib(n uint64) [3]uint64 {
	if n <= 0 {
		return [3]uint64{0, 0, 0}
	}

	sequence := []int{1, 1}
	fn := sequence[0]
	fn1 := sequence[1]

	for i := 2; uint64(fn*fn1) < n; i++ {
		fn = sequence[i-1]
		fn1 = fn + sequence[i-2]
		if uint64(fn*fn1) == n {
			return [3]uint64{uint64(fn), uint64(fn1), 1}
		}
		sequence = append(sequence, fn1)
	}
	return [3]uint64{uint64(fn), uint64(fn1), 0}
}
