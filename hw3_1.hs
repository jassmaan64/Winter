myremoveduplicates :: (Eq a) => [a] -> [a]
myremoveduplicates list
    | null list = []
    | elem (head list)(tail list) = myremoveduplicates(tail list)
    | otherwise = (head list): myremoveduplicates(tail list)


myremoveduplicates_pm :: (Eq a) => [a] -> [a]
myremoveduplicates_pm [] = []
myremoveduplicates_pm (x:xs) 
    | elem x xs = myremoveduplicates_pm xs
    | otherwise = x : myremoveduplicates_pm xs

{-
myintersection :: (Eq a) => [a] -> [a] ->[a]
myintersection list1 list2
    | null list1 = []
    | elem(head list1) list2 = (head list1) : (myintersection(tail list1) list2)
    | otherwise = myintersection(tail list1) list2

myintersection_pm :: (Eq a) => [a] -> [a] ->[a]
myintersection_pm [] _ = []
myintersection_pm (x:xs) list2
    | elem x list2 = x : myintersection_pm (xs) list2
    | otherwise = myintersection_pm xs list2
    


myintersection :: (Eq a) => [a] -> [a] -> [a]
myintersection list1 list2 = intersect (myremoveduplicates list1) list2
  where
    intersect l1 l2 
        | null l1 = []
        | elem (head l1) l2 = head l1 : intersect (tail l1) l2
        | otherwise = intersect (tail l1) l2

--myintersection_pm :: (Eq a) => [a] -> [a] -> [a]
myintersection_pm :: (Eq a) => [a] -> [a] -> [a]
myintersection_pm [] _ = []
myintersection_pm (x:xs) ys
  | elem x ys = x : myintersection_pm xs (remove x ys)
  | otherwise = myintersection_pm xs ys
  where
    remove _ [] = []
    remove z (w:ws)
      | z == w = ws
      | otherwise = w : remove z ws

-}

-- Without pattern matching
myintersection :: (Eq a) => [a] -> [a] -> [a]
myintersection = go []
  where 
    go _ [] _ = []
    go acc (l:ls) list2 
      | l `elem` list2 && not (l `elem` acc) = l : go (l:acc) ls list2
      | otherwise = go acc ls list2


-- With pattern matching
myintersection_pm :: (Eq a) => [a] -> [a] -> [a]
myintersection_pm = go []
  where 
    go _ [] _ = []
    go acc (x:xs) list2
      | x `elem` list2 && not (x `elem` acc) = x : go (x:acc) xs list2
      | otherwise = go acc xs list2

mynthtail:: Int -> [a] -> [a]
mynthtail x list
    | x <= 0 = list
    | null list = []
    | otherwise = mynthtail (x-1) (tail list)

mynthtail_pm :: Int -> [a] -> [a]
mynthtail_pm 0 xs = xs
mynthtail_pm _ [] = []
mynthtail_pm n (x: xs) = mynthtail_pm (n-1) xs

mylast :: [a] -> [a]
mylast list
    | null list = []
    | null (tail list) = [head list]
    | otherwise = mylast(tail list)

mylast_pm :: [a] -> [a]
mylast_pm [] = []
mylast_pm [x] = [x]
mylast_pm list = mylast_pm (tail list)

myreverse :: [a] -> [a]
myreverse list = myreverseHelper [] list
    where
        myreverseHelper acc list
            | null list = acc
            | otherwise = myreverseHelper((head list) : acc) (tail list)

myreverse_pm :: [a] -> [a]
myreverse_pm = myreverseHelper []
    where
        myreverseHelper acc [] = acc
        myreverseHelper acc (x:xs) = myreverseHelper(x: acc) xs

myreplaceall :: (Eq a) => a -> a -> [a] -> [a]
myreplaceall x y list
    | null list = []
    | (head list) == y = x: myreplaceall x y (tail list)
    | otherwise = (head list): myreplaceall x y (tail list)

myreplaceall_pm :: (Eq a) => a -> a -> [a] -> [a]
myreplaceall_pm _ _ [] = []
myreplaceall_pm x y list
    | (head list) == y = x: myreplaceall_pm x y (tail list)
    | otherwise = (head list): myreplaceall x y (tail list)

myordered :: (Ord a) => [a] -> Bool
myordered list
    | null list = True
    | null(tail list) = True
    | (head list) <= (head (tail list)) = myordered(tail list)
    | otherwise = False

myordered_pm :: (Ord a) => [a] -> Bool
myordered_pm [] = True
myordered_pm [x] = True
myordered_pm list
    | (head list) <= (head (tail list)) = myordered(tail list)
    | otherwise = False
