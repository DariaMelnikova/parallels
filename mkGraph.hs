{-# LANGUAGE ScopedTypeVariables #-}

import System.Random
import System.Environment

grFile :: String
grFile = "graph.txt"

main = do
  expSize <- (read <$> head <$> getArgs) :: IO Int
  (vCnt :: Int)   <- randomRIO (0, expSize)
  (eCnt :: Int)   <- randomRIO (vCnt, vCnt^2)
  (startV :: Int) <- randomRIO (0, vCnt)
  endV <- makeAnotherV startV vCnt
  
  writeFile grFile $ show vCnt ++ " " ++ 
                     show eCnt ++ " " ++
                     show startV ++ " " ++
                     show endV ++ "\n"

  genEdges eCnt vCnt
 where
  makeAnotherV startV vCnt = do
    endV <- randomRIO (0, vCnt)
    if endV == startV 
    then makeAnotherV startV vCnt
    else return endV

  genEdges 0 _       = return ()
  genEdges eCnt vCnt = do
    (st  :: Int)  <- randomRIO (0, vCnt)
    (end :: Int)  <- randomRIO (0, vCnt)
    weight :: Int <- randomRIO (0, 511)

    appendFile grFile $ show st ++ " " ++
                        show end ++ " " ++
                        show weight ++ "\n"

    genEdges (eCnt - 1) vCnt
