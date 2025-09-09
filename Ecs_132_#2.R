sim1 <- function(nreps){
  nstops <- 2
  count <- 0
  l1_arr <- 1:nreps
  l1_total <- 0
  l11_total <- 0
  l2_arr <- 1:nreps
  l2_total <- 0
  l22_total <- 0
  l12_total <- 0
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
      l1_total = l1_total + passengers
      l11_total = l11_total + (passengers*passengers)
    }
    else if(passengers == 1){
      l1_total = l1_total + passengers
      l11_total = l11_total + (passengers*passengers)
    }
    
    else 
    {
      l1_total = l1_total + passengers
      l11_total = l11_total + (passengers*passengers)
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
      l2_total = l2_total + passengers
      l22_total = l22_total + (passengers*passengers)
    }
    else if(passengers == 1){
      l2_total = l2_total + passengers
      l22_total = l22_total + (passengers*passengers)
    }
    
    else 
    {
      l2_total = l2_total + passengers
      l22_total = l22_total + (passengers*passengers)
    }
    l12_total = l12_total + (l1_arr[i]*l2_arr[2])
    #print(l12_total)
    #print(passengers)
  }
  #print(l12_total/nreps)
  var_l1= l11_total/nreps - ((l1_total/nreps)*(l1_total/nreps))
  var_l2= l22_total/nreps - ((l2_total/nreps)*(l2_total/nreps))
  cov_l1l2= l12_total/nreps - ((l2_total/nreps)*(l1_total/nreps))
  var_l1_l2 <- var_l1+var_l2-2*(cov_l1l2)
  var_l1_varl2 <- var_l1+var_l2
  #print(var_l1_l2)
  #print(var_l1_varl2)
  
  if(var_l1_l2 == var_l1_varl2)return(TRUE)
  else return(FALSE)
  
}
sim1(1000)
