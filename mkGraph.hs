{-# LANGUAGE ScopedTypeVariables #-}

import System.Random
import System.Environment

grFile :: String
grFile = "graph.txt"

main = do
  (vCnt :: Int)   <- randomRIO (0, 75)
  (eCnt :: Int)   <- randomRIO (vCnt, 10*vCnt)
  (startV :: Int) <- randomRIO (0, vCnt)
  (endV :: Int)   <- randomRIO (0, vCnt)
  
  writeFile grFile $ show vCnt ++ " " ++ 
                     show eCnt ++ " " ++
                     show startV ++ " " ++
                     show endV ++ "\n"

  genEdges eCnt vCnt
 where
  genEdges 0 _       = return ()
  genEdges eCnt vCnt = do
    (st  :: Int)  <- randomRIO (0, vCnt)
    (end :: Int)  <- randomRIO (0, vCnt)
    weight :: Int <- randomRIO (-65536, 65536)

    appendFile grFile $ show st ++ " " ++
                        show end ++ " " ++
                        show weight ++ "\n"

    genEdges (eCnt - 1) vCnt
