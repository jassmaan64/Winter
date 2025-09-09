sim1 <- function(nreps){
  nstops <- 2
  count <- 0
  l1_arr <- 1:nreps
  l1_total <- 0
  l11_total <- 0
  l2_total <- 0
  l22_total <- 0
  for (i in 1:nreps){
    passengers <- 0 
    #stop1 
    if(passengers > 0){
      passengers <- passengers - rbinom (1, passengers, 0.2)
    }
    newpass <- sample(0:2, 1, prob= c(0.5, 0.4, 0.1))
    passengers <- passengers+ newpass
    l1_arr[i] = passengers
    if(passengers == 0)
    {
      l1_total = l1_total + passengers*0.5
      l11_total = l11_total + (passengers*passengers)*0.5
    }
    else if(passengers == 1){
      l1_total = l1_total + passengers*0.4
      l11_total = l11_total + (passenger*passengers)*0.4
    }
      
    else 
    {
      l1_total = l1_total + passengers*0.1
      l11_total = l11_total + (passengers*passengers)*0.1
    }
      
    #stop2
    if(passengers > 0){
      passengers <- passengers - rbinom (1, passengers, 0.2)
    }
    newpass <- sample(0:2, 1, prob= c(0.5, 0.4, 0.1))
    passengers <- passengers+ newpass
    l2_arr[i] = passengers
    if(passengers == 0)
    {
      l2_total = l1_total + passengers*l1_total*0.5
      l22_total = l11_total + (passengers*passengers)*l1_total*0.5
    }
    else if(passengers == 1){
      l2_total = l1_total + passengers*l1_total*0.4
      l22_total = l11_total + (passengers*passengers)*l1_total*0.4
    }
    
    else 
    {
      l2_total = l1_total + passengers*l1_total*0.1
      l22_total = l11_total + (passengers*passengers)*l1_total*0.1
    }
  }
  
}

  