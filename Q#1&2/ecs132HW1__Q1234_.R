#Q1
#Q1a = 0.062
#Q1b = 0.058

#Q1
roulette <- function(){
  df <- data.frame(
    num = sample(0:14, 1),
    color = "green"
  )
  
  if (df$num == 0) {df$color = "green"}
  else if ((df$num %% 2) == 0) {df$color = "red"}
  else {df$color = "black"}
  
  return(df)
}

sim1 <- function(steps, sum_val, step1_val, sims){
  count_AND <- 0
  count_step1 <- 0
  
  for (sim in 1:sims){
    step1 <- 0
    sum <- 0
    
    for (step in 1:steps){
      res <- roulette()
      if (step==1) step1 <- res$num
      sum <- sum + res$num
    }
    
    if (sum==sum_val && step1==step1_val) count_AND <- count_AND + 1
    if (step1==step1_val) count_step1 <- count_step1 + 1
  }
  
  p_AND <- count_AND/sims
  p_step1 <- count_step1/sims
  return (p_AND / p_step1)
}

sim1(3, 17, 4, 10000) #0.07
sim1(3, 17, 5, 10000) #0.05

#Q2
#P(C=0 | X1!=X2) = 0.1052
#P(C=1 | X1!=X2) = 0.0034
#P(C=2 | X1!=X2) = 0

#Q2
sim2 <- function(C_val,p_sent,q_gen,epochs,sims) {
  count_sum <- 0
  count_given <- 0
  
  for (sim in 1:sims) {
    #given X1!=X2
    #X0 <- 2
    X1 <- 0
    X2 <- 0
    C <- 0
    
    for (epoch in 1:epochs){
      sent <- 0
      gen <- 0
      
      if (epoch==1) {
        for (node in 1:2) {
          
          #both nodes are active, so no need to generate msg
          
          #need to send msg
          if (runif(1) < p_sent) sent <- sent + 1 #sent --> inactive
        }
        
        if (sent == 2) {
          C <- C + 1
          sent <- 0
        }
        
        X1 <- 2-sent
      }
      
      else { #epoch==2
        sent <- 0
        gen <- 0
        active <- X1
        inactive <- 2-X1
        
        #during epoch
        for (node in 1:2) {
          
          #need to generate msg, if at least 1 node is inactive
          if ( (inactive > 0) && (runif(1) < q_gen) ) { #gen --> active
            gen <- gen + 1
            inactive <- inactive - 1
            active <- active + 1
          }
          
        }
        
        #at the end of epoch
        for (node in 1:2) {
          
          #need to send msg, if at least 1 node is active
          if ( (active > 0) && (runif(1) < p_sent) ) { #sent --> inactive
            sent <- sent + 1
          }
          if (sent == 2) C <- C + 1 #sent = 0
          else {
            active <- active - sent
            inactive <- inactive + sent
          }
          
        }
        
        X2 <- active
      }
      
    }
    
    if (X1 != X2) count_given <- count_given + 1
    if ( (C == C_val) && (X1 != X2) ) count_sum <- count_sum + 1
  }
  
  p_sum <- count_sum / sims
  p_given <- count_given / sims
  return (p_sum / p_given)
}

p <- 0.4
q <- 0.8
sim2(0,p,q,2,10000) #0.74
sim2(1,p,q,2,10000) #0.22
sim2(2,p,q,2,10000) #0.04

#Q3
#Q3a = 0.04
#Q3b = 0.01

#Q3
cards <<- list()

init_cards <- function(){
  card <- data.frame(
    type = "C",
    num = 1
  )

  cards <<- list()
  for (i in 1:52) cards <<- append(cards, list(card))

  j <- 1
  for (i in 1:13) {
    cards[[i]]$type <<- "C"
    cards[[i]]$num <<- j
    j <- j+1
  }
  
  j <- 1
  for (i in 14:26) {
    cards[[i]]$type <<- "D"
    cards[[i]]$num <<- j
    j <- j+1
  }
  
  j <- 1
  for (i in 27:39) {
    cards[[i]]$type <<- "H"
    cards[[i]]$num <<- j
    j <- j+1
  }
  
  j <- 1
  for (i in 40:52) {
    cards[[i]]$type <<- "S"
    cards[[i]]$num <<- j
    j <- j+1
  }
}

get_card <- function(start){
  if (start == 1) init_cards()
  
  idx <- sample(1:length(cards), 1)
  card <- cards[[idx]]

  i <- 1
  if (card$type=="C") i <- 1
  else if (card$type=="D") i <- 14
  else if (card$type=="H") i <- 27
  else if (card$type=="S") i <- 40
  j <- card$num
  cards <<- cards[-(i+j-1)]
  
  return(card)
}

sim3 <- function(vals, sims) {
  count_ace <- 0
  count_dm <- 0
  
  for (sim in 1:sims) {
    num_ace <- 0
    num_dm <- 0
    
    for (val in 1:vals) {
      start <- 0
      if (val==1) start <- 1
      card <- get_card(start)
      
      if (card$num == 1) num_ace <- num_ace + 1
      if (card$type == "D") num_dm <- num_dm + 1
    }
    
    if (num_ace == 2) count_ace <- count_ace + 1
    if (num_dm == 4) count_dm <- count_dm + 1
  }
  
  cat("Q3a",count_ace/sims,"\n")
  cat("Q3b",count_dm/sims,"\n")
}

sim3(5,1000)
#Q3a 0.04 
#Q3b 0.01

#Q4
#Q4a = 30C5 * 25C6
#Q4b
#either both in group of size 5: 30C2*28C3*25C6 / (30C5 * 25C6)
#or both in group of size 6: 30C2*28C4*24C5 / (30C5 * 25C6)
#P = 1 - (30C2*28C3*25C6 / (30C5 * 25C6) + 30C2*28C4*24C5 / (30C5 * 25C6))

#Q5 = 0.549


