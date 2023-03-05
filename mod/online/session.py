from tools import class_ascendancy
import copy

def set_bit(value, bit):
    return value | (1<<bit)

def clear_bit(value, bit):
    return value & ~(1<<bit)

def num_to_list(num):
    result = []
    for i in range(8):
        result.append(num & 1)
    return result

def list_to_num(list):
    result = 0
    for i in range(8):
        result += list[i] << i
    return result

def swap_first_and_x(list, x):
    return [list[x]]+list[1:x]+[list[0]]+list[x+1:]

class Session:
    def __init__(self, owner_sid):
        self.players = [owner_sid, None, None, None, None, None, None]
        self.owner_sid = owner_sid
        self.num_players = 1
        self.game_running = False
        
        self.race: list[class_ascendancy.Race] = []

        self.current_day = 0

        self.race_count = 0

        self.research_items: list[class_ascendancy.ResearchItem] = []

        self.current_research_items: list[int] = []

        self.star_systems: list[class_ascendancy.StarSystem] = []

        self.planet_structures: list[class_ascendancy.PlanetStructure] = []

        self.planets: list[class_ascendancy.Planet] = []

        self.ships: list[class_ascendancy.Ship] = []

        self.diplomacies: list[class_ascendancy.Diplomacy] = []

        self.starlanes: list[class_ascendancy.StarLane] = []

        self.starlanes_controlledby: dict[int] = {}

    def add_player(self, sid):
        for i in range(7):
            if self.players[i] is None:
                self.players[i] = sid
                self.num_players += 1
                return
        else:
            raise Exception('No free slots')
        
    
    def remove_player(self, sid):
        self.players[self.players.index(sid)] = None
        self.num_players -= 1
    
    def get_player(self, sid):
        return self.players.index(sid)
    
    def set_race(self, sid, race:class_ascendancy.Race, index:int):
        if self.owner_sid == sid:
            self.race[index] = race
        elif self.get_player(sid) == index:
            self.race[self.get_player(sid)] = race
    
    def get_all_race(self, sid):
        return swap_first_and_x(self.race, self.get_player(sid))
    
    def set_research_items(self, sid, research_item:class_ascendancy.ResearchItem, index:int):
        if self.owner_sid == sid:
            if index >= len(self.research_items):
                self.research_items.append(research_item)
            for i in range(len(self.players)):
                if self.players[i] is not None:
                    continue
                if 1 << i & research_item.KnownBy:
                    self.research_items[index].KnownBy = set_bit(research_item.KnownBy, i)
                else:
                    self.research_items[index].KnownBy = clear_bit(research_item.KnownBy, i)

                if 1 << i & research_item.PendingAcknowledgement:
                    self.research_items[index].PendingAcknowledgement = set_bit(research_item.PendingAcknowledgement, i)
                else:
                    self.research_items[index].PendingAcknowledgement = clear_bit(research_item.PendingAcknowledgement, i)
        
        bitmask = self.research_items[index].KnownBy
        if 1 & research_item.KnownBy:
            bitmask = set_bit(bitmask, self.get_player(sid))
        else:
            bitmask = clear_bit(bitmask, self.get_player(sid))
        
        self.research_items[index].KnownBy = bitmask

        bitmask = self.research_items[index].PendingAcknowledgement
        if 1 & research_item.PendingAcknowledgement:
            bitmask = set_bit(bitmask, self.get_player(sid))
        else:
            bitmask = clear_bit(bitmask, self.get_player(sid))
        self.research_items[index].PendingAcknowledgement = bitmask
    
    def get_research_items(self, sid, index:int):
        result = copy.deepcopy(self.research_items[index])
        bitmask = num_to_list(result.KnownBy)
        bitmask = swap_first_and_x(bitmask, self.get_player(sid))
        result.KnownBy = list_to_num(bitmask)

        bitmask = num_to_list(result.PendingAcknowledgement)
        bitmask = swap_first_and_x(bitmask, self.get_player(sid))
        result.PendingAcknowledgement = list_to_num(bitmask)
        return result
    
    def get_all_research_items(self, sid):
        result = []
        for i in range(len(self.research_items)):
            result.append(self.get_research_items(sid, i))
        return result
    
    def set_current_research_items(self, sid, index:int, value:int):
        if self.owner_sid == sid:
            self.current_research_items[index] = value
        elif self.get_player(sid) == index:
            self.current_research_items[self.get_player(sid)] = value
    
    def get_current_research_items(self, sid, index:int):
        return self.current_research_items[index]
    
    def get_all_current_research_items(self, sid):
        return swap_first_and_x(self.current_research_items, self.get_player(sid))
    
    def set_star_systems(self, sid, star_system:class_ascendancy.StarSystem, index:int):
        if self.owner_sid == sid:
            if index >= len(self.star_systems):
                self.star_systems.append(star_system)
            for i in range(len(self.players)):
                if 1 << i & star_system.KnownBy:
                    self.star_systems[index].ShipIndicator = set_bit(star_system.KnownBy, i)
                else:
                    self.star_systems[index].ShipIndicator = clear_bit(star_system.KnownBy, i)
        else:
            bitmask = self.star_systems[index].ShipIndicator
            if 1 & star_system.ShipIndicator:
                bitmask = set_bit(bitmask, self.get_player(sid))
            else:
                bitmask = clear_bit(bitmask, self.get_player(sid))
            self.star_systems[index].ShipIndicator = bitmask
    
    def get_star_systems(self, sid, index:int):
        result = copy.deepcopy(self.star_systems[index])
        bitmask = num_to_list(result.ShipIndicator)
        bitmask = swap_first_and_x(bitmask, self.get_player(sid))
        result.ShipIndicator = list_to_num(bitmask)
        return result

    def get_all_star_systems(self, sid):
        result = []
        for i in range(len(self.star_systems)):
            result.append(self.get_star_systems(sid, i))
        return result

    def set_planet_structures(self, sid, planet_structure:class_ascendancy.PlanetStructure, index:int):
        if self.owner_sid == sid:
            if index >= len(self.planet_structures):
                self.planet_structures.append(planet_structure)
        
        self.planet_structures[index] = planet_structure
    
    def get_planet_structures(self, sid, index:int):
        return self.planet_structures[index]
    
    def get_all_planet_structures(self, sid):
        return self.planet_structures
    
    def set_planet(self, sid, planet:class_ascendancy.Planet, index:int):
        if self.owner_sid == sid:
            if index >= len(self.planets):
                self.planets.append(planet)
            if self.players[planet.OwnerRaceIndex] is None:
                self.planets[index] = planet
        if planet.OwnerRaceIndex == 0:
            planet.OwnerRaceIndex = self.get_player(sid)
            self.planets[index] = planet
    
    def get_planet(self, sid, index:int):
        result = copy.deepcopy(self.planets[index])
        if result.OwnerRaceIndex == self.get_player(sid):
            result.OwnerRaceIndex = 0
        elif result.OwnerRaceIndex == 0:
            result.OwnerRaceIndex = self.get_player(sid)
        return result
    
    def get_all_planets(self, sid):
        result = []
        for i in range(len(self.planets)):
            result.append(self.get_planet(sid, i))
        return result
    
    def set_ships(self, sid, ship:class_ascendancy.Ship, index:int):
        if self.owner_sid == sid:
            if index >= len(self.ships):
                self.ships.append(ship)
            if self.players[ship.OwnerRaceIndex] is None:
                self.ships[index] = ship
        if ship.OwnerRaceIndex == 0:
            ship.OwnerRaceIndex = self.get_player(sid)
            self.ships[index] = ship
    
    def get_ships(self, sid, index:int):
        result = copy.deepcopy(self.ships[index])
        if result.OwnerRaceIndex == self.get_player(sid):
            result.OwnerRaceIndex = 0
        elif result.OwnerRaceIndex == 0:
            result.OwnerRaceIndex = self.get_player(sid)
        return result
    
    def get_all_ships(self, sid):
        result = []
        for i in range(len(self.ships)):
            result.append(self.get_ships(sid, i))
        return result
    
    def set_diplomacies(self, sid, diplomacy:class_ascendancy.Diplomacy, index:int):
        if self.owner_sid == sid:
            if index >= len(self.diplomacies):
                self.diplomacies.append(diplomacy)
            if self.players[diplomacy.RaceIndex] is None:
                self.diplomacies[index] = diplomacy
        if diplomacy.RaceIndex == 0:
            diplomacy.RaceIndex = self.get_player(sid)
            diplomacy.RelationshipToPlayer1Trackers = swap_first_and_x(diplomacy.RelationshipToPlayer1Trackers, self.get_player(sid))
            diplomacy.RelationshipToPlayerStates = swap_first_and_x(diplomacy.RelationshipToPlayer2Trackers, self.get_player(sid))
            self.diplomacies[index] = diplomacy
        
    def get_diplomacies(self, sid, index:int):
        result = copy.deepcopy(self.diplomacies[index])
        if result.RaceIndex == self.get_player(sid):
            result.RaceIndex = 0
            result.RelationshipToPlayer1Trackers = swap_first_and_x(result.RelationshipToPlayer1Trackers, self.get_player(sid))
            result.RelationshipToPlayerStates = swap_first_and_x(result.RelationshipToPlayer2Trackers, self.get_player(sid))
        elif result.RaceIndex == 0:
            result.RaceIndex = self.get_player(sid)
            result.RelationshipToPlayer1Trackers = swap_first_and_x(result.RelationshipToPlayer1Trackers, self.get_player(sid))
            result.RelationshipToPlayerStates = swap_first_and_x(result.RelationshipToPlayer2Trackers, self.get_player(sid))
        return result
    
    def get_all_diplomacies(self, sid):
        result = []
        for i in range(len(self.diplomacies)):
            result.append(self.get_diplomacies(sid, i))
        return result
    
    def set_starlanes(self, sid, starlane:class_ascendancy.StarLane, index:int):
        if self.owner_sid == sid:
            if index >= len(self.starlanes):
                self.starlanes.append(starlane)
            self.starlanes[index] = starlane
        
        if starlane.ControlledByPlayer == 1:
            self.starlanes_controlledby[index] = self.get_player(sid)
        
        bitmask = self.starlanes[index].KnownBy
        if 1 & starlane.KnownBy:
            bitmask = set_bit(bitmask, self.get_player(sid))
        else:
            bitmask = clear_bit(bitmask, self.get_player(sid))
        
        self.starlanes[index].KnownBy = bitmask

        self.starlanes[index].StarlaneType = starlane.StarlaneType
    
    def get_starlanes(self, sid, index:int):
        result = copy.deepcopy(self.starlanes[index])
        bitmask = num_to_list(result.KnownBy)
        bitmask = swap_first_and_x(bitmask, self.get_player(sid))
        result.KnownBy = list_to_num(bitmask)
        if self.starlanes_controlledby[index] == self.get_player(sid):
            result.ControlledByPlayer = 1
        else:
            result.ControlledByPlayer = 0
        return result

    def get_all_starlanes(self, sid):
        result = []
        for i in range(len(self.starlanes)):
            result.append(self.get_starlanes(sid, i))
        return result