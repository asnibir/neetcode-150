class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # cars = []
        # for pos, spd in zip(position, speed):
        #     t = (target - pos) / spd
        #     cars.append((pos, t))

        cars = [(p, (target - p)/s) for p, s in zip(position, speed)]

        cars.sort(reverse = True)

        fleet = 0
        curTime = 0.0 
        for pos, time in cars:
            if time > curTime:
                fleet += 1
                curTime = time
    
        return fleet


        