# Lab3

## Common tips about Placeables

Model data about Placeable is presented by class Placeable, which contains x and y coordinates. 

Model data about Creature is presented by class Creature, which contains primary and secondary parameters. 
Creature is derived class of Placeable, so it contains all data of Placeable.

Primary parameters are presented by struct Primary, which contains:
1. Power (field power in struct)
2. Ability (field ability in struct)
3. Endurance (field endurance in struct)
4. Health limit (field health_limit in struct)

Secondary parameters are presented by struct Secondary, which contains:
1. Bonus damage (computed by power)
2. Bonus defence (computed by ability)
3. Unlocking (computed by ability)
4. Consumables limit (computed by endurance)
5. Health (field health in struct)

Opportunity to move is implemented by interface class Moveable. This interface has pure virtual method be_moved.

Model data about Player is presented by class Player, which is derived by class Creature and Moveable.
Method be_moved is override as just setting gotten coords into Player data coords.

## Drawing information about Player on screen.




