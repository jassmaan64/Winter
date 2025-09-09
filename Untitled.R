problem1 <- function(total, spin1, nReps=1000){
   count1 <- 0
   for(i in 1:nReps){
     spin2= sample(0:6,1,replace=TRUE)
     spin3= sample(0:6,1,replace=TRUE)
     sum <- spin1+spin2+spin3
     
     if(sum == total){
       count1 <- count1+1
     }
   }
   return(count1/nReps)
}