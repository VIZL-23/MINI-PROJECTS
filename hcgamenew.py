import random
print("""
Welcome to Hand Cricket!

Hand Cricket is a fun, casual game where you play 'cricket' with numbers. 
In this computer version, you'll play against the computer, aiming to score more runs than it to win!

Basic Rules of Hand Cricket:

1. Objective:
   The goal is to score more runs than the opponent. 
   There are two roles in the game: batting and bowling.
      - When you're batting, you score runs.
      - When you're bowling, you try to prevent the computer from scoring.

2. The Toss:
   The game starts with a toss to decide who bats first.
      - You'll choose "odd" or "even" and select a number between 0 and 10.
      - The computer will also select a number.
      - If the sum of the two numbers is even, the player who chose "even" wins the toss.
      - If the sum is odd, the player who chose "odd" wins the toss.
      - The toss winner gets to choose whether to bat or bowl first.

3. Batting:
      - When batting, you'll input a number (run) between 0 and 10.
      - The computer will simultaneously choose a "ball" number between 0 and 10.
      - If the numbers don't match, your chosen number is added to your score.
      - If the numbers match, you're "out," and your final score is set.
      
4. Bowling:
      - When bowling, the computer will select a number (run) between 0 and 10.
      - You'll select a "ball" number between 0 and 10.
      - If the numbers don't match, the computer's number is added to its score.
      - If the numbers match, the computer is "out," and its score is set.

5. Winning:
   The player with the higher score at the end wins the match!
   
Let's get started and have fun!
""")

def game():

    def eml(n):
        for i in range(n):
            print("")
    eml(2)

    def eo_ask(eo=""):
        try:
            eo=str(input("ODD OR EVEN(o/e):"))
            if eo=="o" or eo=="e":
                return eo
            else:
                print("Enter valid input, e for even and o for odd")
                eml(1)
                eo_ask(eo="")
        except ValueError:
            print("Enter valid input, e for even and o for odd")
            eml(1)
            eo_ask(eo="")
    toss_ask=eo_ask(eo="")   

    def toss(sum_toss=0):
        try:
            comp_toss=random.randint(0,10)
            man_toss=int(input("Enter your toss number between 0 to 10:"))
            if man_toss>-1 and man_toss<11:
                sum_toss=man_toss+comp_toss
            else:
                print("Please enter a number between 0 and 10")
                eml(2)
                toss()

        except ValueError:
            print("Enter valid integer between 0 to 10")
            eml(2)
            toss()
        else:
            print("Your choice:",man_toss)
            print("Computer choice:",comp_toss)
            eml(1)
            print("The sum is ",comp_toss+man_toss)
            eml(2)
            return(sum_toss)
    toss_result=toss(sum_toss=0)

    def decide():
        if (toss_ask=="o" and toss_result%2==0) or (toss_ask=="e" and toss_result%2!=0) :
            print("COMPUTER HAS WON THE TOSS")
            comp_decide=random.randint(1,2)
            if comp_decide==1:
                print("COMPUTER HAS DECIDED TO BAT FIRST")
                eml(2)
                comp_bat_first()
                return 0
            if comp_decide==2:
                print("COMPUTER HAS DECIDED TO BOWL FIRST")
                eml(2)
                comp_bowl_first()
                return 0

        if (toss_ask=="o" and toss_result%2!=0) or (toss_ask=="e" and toss_result%2==0) :
            print("YOU HaVE WON THE TOSS")
            ask=int(input("""DO YOU WaNT TO 
            1.BAT
            2.BOWL 
            ENTER 1 to bat OR 2 to bowl : """))
            try:
                if ask==1:
                    print("You have choosen to bat first")
                    eml(2)
                    comp_bowl_first()
                    return 0
                if ask==2:
                    print("You have choosen to bowl first")
                    eml(2)
                    comp_bat_first()
                    return 0
                else:
                    print("Give a valid answer (1 or 2) either to bat or bowl")
                    decide()
        
            except ValueError:
                print("Give a valid answer (1 or 2) either to bat or bowl")
                decide()

    def comp_bowl_first():
        a=0
        b1=0
        while True:
            x1=random.randint(1,10) 
            try:
                b1=int(input("Enter your hit from 0 to 10: "))
                eml(1)
                if (b1>-1 and b1<11) and b1!=x1:
                    print("YOUR HIT INPUT:",b1)
                    print("COMPUTER BALL INPUT:",x1)
                    eml(1)
                    a+=b1
                    print("YOUR CURRENT SCORE",a)
                    eml(2)
                if (b1>-1 and b1<11) and b1==x1:
                    print("YOUR HIT INPUT:",b1)
                    print("COMPUTER BALL INPUT:",x1)
                    eml(1)
                    print("OUT! OUT! OUT!")
                    eml(1)
                    print("YOUR FINAL SCORE",a)
                    eml(2)
                    break
                if (b1<0 and b1>10):
                    print("Please enter a valid input between 0 to 10")
                    eml(2)
            except ValueError:   
                print("Please give a valid input")
    
        print("GET READY TO BOWL:")
        print("COMPUTER NEEDS",a+1,"runs to win this match")
        
        a1=0
        b2=0
        while True:  
            x2=random.randint(0,10) 
            try:
                b2=int(input("Enter your ball from 1 to 10: "))
                if (b2>0 and b2<11) and b2!=x2:
                    print("YOUR BALL INPUT:",b2)
                    print("COMPUTER HIT INPUT:",x2)
                    eml(1)
                    a1+=x2
                    if a1>a:
                        print("COMPUTER CURRENT SCORE",a1)
                        print("OWW!! COMPUTER HAS CHASED THE SCORE AND YOU HAVE LOST")
                        break
                        
                    else:
                        print("COMPUTER CURRENT SCORE",a1)
                        print("COMPUTER NEEDS",a-a1+1,"RUNS TO WIN")
                        eml(2)
                if (b2>0 and b2<11) and b2==x2:
                    if a1<a:
                        print("YOUR HIT INPUT:",b2)
                        print("COMPUTER BALL INPUT:",x2)
                        eml(1)
                        print("OUT! OUT! OUT!")
                        eml(1)
                        print("COMPUTER FINAL SCORE IS",a1)
                        eml(1)
                        print("YOU HAVE WON THE MATCH BY",a-a1+1,"RUNS")
                        break
                       
                    else:
                        print("YOUR HIT INPUT:",b2)
                        print("COMPUTER BALL INPUT:",x2)
                        eml(1)
                        print("OUT! OUT! OUT!")
                        eml(1)
                        print("COMPUTER FINAL SCORE IS",a1)
                        eml(1)
                        print("THE MATCH IS DRAWN :)")                      
                        break

                if (b1<0 and b1>10):
                    print("Please enter a valid input between 0 to 10")
                    eml(2)
            except ValueError:   
                print("Please give a valid input")

    def comp_bat_first():
        a=0
        b1=0
        while True:
            x1=random.randint(0,10) 
            b1=int(input("Enter your ball from 1 to 10: "))
            try:
                eml(1)
                if (b1>0 and b1<11) and type(b1)==int and b1!=x1:
                    print("YOUR BALL INPUT:",b1)
                    print("COMPUTER HIT INPUT:",x1)
                    eml(1)
                    a+=x1
                    print("COMPUTER'S SCORE",a)
                    eml(2)
                if (b1>0 and b1<11) and type(b1)==int and b1==x1:
                    print("YOUR BALL INPUT:",b1)
                    print("COMPUTER'S BALL INPUT:",x1)
                    eml(1)
                    print("OUT! OUT! OUT!")
                    eml(1)
                    print("COMPUTER FINAL SCORE IS",a)
                    eml(2)
                    break
                if (b1<1 and b1>10) and type(b1)!=int:
                    print("Please enter a valid input between 1 to 10")
                    eml(2)
            except ValueError:   
                print("Please give a valid input")   
    
        print("GET READY TO BAT:")
        print("YOU NEED",a+1,"runs to win this match")
        
        a1=0
        b2=0
        while True:  
            x2=random.randint(1,10) 
            try:
                b2=int(input("Enter your hit from 0 to 10: "))
                if (b2>0 and b2<11) and type(b2)==int and b2!=x2:
                    print("YOUR HIT INPUT:",b2)
                    print("COMPUTER BALL INPUT:",x2)
                    eml(1)
                    a1+=b2
                    if a1>a:
                        print("YOUR CURRENT SCORE",a1)
                        print("YEAHH!! YOU HAVE WON THE MATCH!!!")
                        break
                       
                    else:
                        print("YOUR CURRENT SCORE",a1)
                        print("YOU NEED",a-a1+1,"RUNS TO WIN")
                        eml(2)
                if (b2>0 and b2<11) and type(b2)==int and b2==x2:
                    if a1<a:
                        print("YOUR HIT INPUT:",b2)
                        print("COMPUTER BALL INPUT:",x2)
                        eml(1)
                        print("OUT! OUT! OUT!")
                        eml(1)
                        print("YOUR FINAL SCORE IS",a1)
                        eml(1)
                        print("YOU HAVE LOST THE MATCH BY",a-a1+1,"RUNS")
                        break
                        
                    else:
                        print("YOUR HIT INPUT:",b2)
                        print("COMPUTER BALL INPUT:",x2)
                        eml(1)
                        print("OUT! OUT! OUT!")
                        eml(1)
                        print("YOUR FINAL SCORE IS",a1)
                        eml(1)
                        print("THE MATCH IS DRAWN :)")
                        break
                      
                if (b1<0 and b1>10) and type(b1)!=int:
                    print("Please enter a valid input between 0 to 10")
                    eml(2)
            except ValueError:   
                print("Please give a valid input")

    decide()

game()

