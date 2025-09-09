mycount: (Eq a) => [a] -> a -> Int
mycount list x
	| null list = 0
	| (head list) == x = 1 + mycount (tail list) x
	| otherwise = mycount (tail list) x

mycount_pm :: (Eq a) => [a] -> a -> Int
mycount_pm [] = 0
mycount_pm (x:xs) y
	| x == y = 1 + mycount_pm xs y
	| otherwise = mycount_pm xs y

