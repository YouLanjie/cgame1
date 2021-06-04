# game-1
这是一个小游戏
我曾经做过一个python小游戏，那个游戏功能不齐全，而且还有很多bug。
现在我用c语言把它还原并增加了很多东西，例如：主菜单、游戏记录、帮助、更先进的玩法……

> 2021.06.01
> 继续完善

## 日志
|    日期    |       描述     |
|:----------:|:--------------:|
| 2021.06.01 | 向cgame2功能开发 |
| 2021.06.04 | 修正README中的代码 |
| 2021.06.04 | 修改代码，增加功能 |

---

> 原来的代码：

```python
import time
import random

b=input("你想玩几局？")
c=0
x_c=0
y_c=0
print("")
print("")
print("")
print("本次局数："+str(b))
time.sleep(3)

for c in range(0,int(b)):
    c=c+1
    print("")
    print("")
    print("第"+str(c)+"局")
    print("")
    
    x_a = random.randint(100,400)
    x_b = random.randint(5,40)

    y_a = x_a
    y_b = random.randint(5,40)

    print("史蒂夫的血量："+str(x_a))
    print("史蒂夫的初始攻击力："+str(x_b))
    print("")
    print("艾力克斯的血量："+str(y_a))
    print("艾力克斯的初始攻击力："+str(y_b))

    print("准备")

    time.sleep(3)

    print("开始")

    time.sleep(1)

    while x_a > 0 and y_a > 0:
        x_a = x_a - y_b
        y_a = y_a - x_b
        
        if x_a<0:
            x_a=0
        if y_a<0:
            y_a=0
            
        print("艾力克斯发动攻击，史蒂夫的血量变成了："+str(x_a))
        y_b=random.randint(5,40)
        print("这时艾力克斯的攻击力变成了："+str(y_b))
        print("史蒂夫发动攻击，艾力克斯的血量变成了："+str(y_a))
        x_b=random.randint(5,40)
        print("这时史蒂夫的攻击力变成了："+str(x_b))
        time.sleep(1.5)
        
        print("")

    if x_a > 0 and y_a <= 0:
        print("第"+str(c)+"局史蒂夫获胜")
        print("")
        x_c=x_c+1

    else:
        print("第"+str(c)+"局艾力克斯获胜")
        print("")
        y_c=y_c+1
        
    print("3秒间隔时间")
    time.sleep(3)
print("")
print("    结算")
time.sleep(1)
print("本次战斗共"+str(b)+"局。""史蒂夫胜利了"+str(x_c)+"局。""艾力克斯胜利了"+str(y_c)+"局")
time.sleep(1)
print("所以本次战斗")
time.sleep(1)
if x_c>y_c:
    print("史蒂夫胜出")

if x_c<y_c:
    print("艾力克斯胜出")

if x_c==y_c:
    print("双方平局")
```
另一串：
```python
import time
import random

game_player_c = 0
game_enemy_c = 0
game = input("你想玩几局？")

for a in range(0,int(game)):
    a = a+1
    game_player_a = random.randint(100,400)
    game_player_b = random.randint(10,60)
    game_enemy_a = game_player_a
    game_enemy_b = random.randint(10,60)

    print()
    print("第"+str(a)+"局")
    print()
    time.sleep(1)
    
    print("你的血量："+str(game_player_a))
    time.sleep(0.3)
    print("你的攻击力："+str(game_player_b))
    time.sleep(0.6)
    print()
    print("敌人的血量："+str(game_enemy_a))
    time.sleep(0.3)
    print("敌人的攻击力："+str(game_enemy_b)) 
    print()
    
    while game_player_a > 0 and game_enemy_a > 0:
        time.sleep(1)
        print("你想要进攻还是要防守？")
        print()
        print("1_进攻")
        b = input("2_防守")
    
        if b < str(2):
            game_enemy_a = game_enemy_a - game_player_b
            if game_enemy_a < 0:
                game_enemy_a = 0
            print("敌人的血量："+str(game_enemy_a))
            print()
            time.sleep(0.5)
            game_player_a = game_player_a - game_enemy_b
            if game_player_a < 0:
                game_player_a = 0
            print("你的血量："+str(game_player_a))
            print()
            print()
            time.sleep(0.6)
        else:
            game_player_a = game_player_a - 5
            if game_player_a < 0:
                game_player_a = 0
            print("敌人的血量："+str(game_enemy_a))
            print()
            time.sleep(0.3)
            print("你的血量："+str(game_player_a))
            print()
            print()
            time.sleep(0.6)
        
        if game_player_a > 0 and game_enemy_a <= 0:
            print("第"+str(a)+"局玩家获胜")
            print("")
            game_player_c = game_player_c + 1
        
        if game_player_a <= 0 and game_enemy_a > 0:
            print("第"+str(a)+"局敌人获胜")
            print("")
            game_enemy_c = game_enemy_c + 1        
print()
print()
print()
print("       结算")
print("本次战斗玩家胜利了"+str(game_player_c)+"局")
print("本次战斗敌人胜利了"+str(game_enemy_c)+"局")
print("       所以")
print("     本次战斗")

if game_enemy_c < game_player_c:
    print("玩家胜利")

if game_enemy_c > game_player_c:
    print("敌人胜利")
```

