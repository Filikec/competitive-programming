

put :: a -> [a] -> [a]
put e [] = []
put e (x:xs) = x:e:xs