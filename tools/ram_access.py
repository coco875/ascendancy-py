import pymem
import ascendancy_lib as ascendancy


class Game:
    def __init__(self, old_method = False):
        self.old_method = old_method
        # Init addresses

        self.adress = {}

        self.size_struct_planet_structures = ascendancy.size_of_struct(ascendancy.asc.Model.PlanetStructure)

        self.size_struct_research = ascendancy.size_of_struct(ascendancy.asc.Model.ResearchItem)

        self.size_struct_planet = ascendancy.size_of_struct(ascendancy.asc.Model.Planet)

        self.size_struct_ship = ascendancy.size_of_struct(ascendancy.asc.Model.Ship)-4 # maybe the -4 is for the index
        
        self.systems_address = 0
        self.size_struct_systems = ascendancy.size_of_struct(ascendancy.asc.Model.StarSystem)

        self.size_struct_diplomacy = ascendancy.size_of_struct(ascendancy.asc.Model.Diplomacy)

        self.size_struct_starlanes = ascendancy.size_of_struct(ascendancy.asc.Model.StarLane)

        self.size_struct_current_research_items = 2 # short

    def get_paused_address(self) -> int:
        """Get Paused Address"""
        result = pymem.pattern.pattern_scan_all(self.dosbox_ascendancy.process_handle, br"DATA\\SMRACE19\.SHP")

        self.paused_address = result-0x7E4

        self.adress["paused"] = self.paused_address
        return self.paused_address

    def get_number_of_ships_address(self) -> int:
        """Get Number of ships Address"""
        self.number_of_ships_address = self.paused_address-0x5BC6D

        self.adress["number of ships"] = self.number_of_ships_address
        return self.number_of_ships_address

    def get_number_of_ships(self) -> int:
        """Get Number of ships"""
        self.number_of_ships = self.dosbox_ascendancy.read_int(self.number_of_ships_address)

        return self.number_of_ships

    def set_number_of_ships(self, n: int):
        """Set Number of ships"""
        self.dosbox_ascendancy.write_int(self.number_of_ships_address, n)

    def get_research_address(self) -> int:
        """Get Research Address"""
        if self.old_method:
            a_research_name = b"".join([i.encode() for i in save.ResearchItems[0].Name])

            result = pymem.pattern.pattern_scan_all(self.dosbox_ascendancy.process_handle, a_research_name)

            self.research_address = result
        else:
            a_research_name = b"Orbital Structures"

            result = pymem.pattern.pattern_scan_all(self.dosbox_ascendancy.process_handle, a_research_name)

            self.research_address = result

        self.adress["ResearchItem"] = self.research_address

        return self.research_address

    def get_research(self, i) -> ascendancy.class_ascendancy.ResearchItem:
        buff = self.dosbox_ascendancy.read_bytes(self.research_address+i*self.size_struct_research, self.size_struct_research)
        research = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Enum.ResearchItem)
        return research

    def get_all_research(self) -> list[ascendancy.class_ascendancy.ResearchItem]:
        l = []
        for i in range(66):
            l.append(self.get_research(i))
        return l

    def set_research(self, i, research: ascendancy.class_ascendancy.ResearchItem):
        buff = ascendancy.Struct_to_bytes(research)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.research_address+i*self.size_struct_research, buff, self.size_struct_research)

    def set_all_research(self, research_list: list[ascendancy.class_ascendancy.ResearchItem]):
        for i in range(len(research_list)):
            self.set_research(i, research_list[i])

    def get_number_of_days_address(self):
        """Get Number of days Address"""
        self.days_address = self.research_address-0x61936

        self.adress["Days"] = self.days_address

        return self.days_address

    def get_number_of_days(self) -> int:
        """Get Number of days"""
        return self.dosbox_ascendancy.read_int(self.days_address)

    def set_number_of_days(self, days: int):
        """Set Number of days"""
        self.dosbox_ascendancy.write_int(self.days_address, days)

    def get_number_of_race_address(self):
        """Get Number of race Address"""
        self.race_number_address = self.research_address-0x60BAE

        self.adress["race number"] = self.race_number_address

        return self.race_number_address

    def get_menu_address(self):
        """Get Menu on screen Address"""
        self.menu_address = self.research_address+0x9E3E

        self.adress["Menu"] = self.menu_address

        return self.menu_address

    def get_race_address(self):
        """Get Race Address"""
        self.race_address = self.research_address+0x327D6

        self.adress["Race"] = self.race_address

        return self.race_address

    def get_race(self, i) -> ascendancy.class_ascendancy.Race:
        buff = self.dosbox_ascendancy.read_bytes(self.race_address+i*0x4, 0x4)
        race = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Enum.Race)
        return race

    def get_all_race(self) -> list[ascendancy.class_ascendancy.Race]:
        l = []
        for i in range(7):
            l.append(self.get_race(i))
        return l

    def set_race(self, i, race: ascendancy.class_ascendancy.Race):
        buff = ascendancy.Struct_to_bytes(race)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.race_address+i*0x4, buff, 0x4)

    def set_all_race(self, races: list[ascendancy.class_ascendancy.Race]):
        for i in range(7):
            self.set_race(i,races[i])

    def get_planet_address(self):
        """Get Planet Address"""
        if self.old_method:
            a_planet_name = b"".join([i.encode() for i in save.Planets[0].Name])

            result = pymem.pattern.pattern_scan_all(self.dosbox_ascendancy.process_handle, a_planet_name)

            result -= 2 # -2 because of the 2 bytes of the short Unknown_34
            result -= 2 # -2 because of the 2 bytes of the short BlackSquareCount
            result -= 2 # -2 because of the 2 bytes of the short OrbitalSquareCount
            result -= 2 # -2 because of the 2 bytes of the short FreeSquareCount
            result -= 2 # -2 because of the 2 bytes of the short TotalSquareCount
            result -= 2 # -2 because of the 2 bytes of the short PlanetSquareCount
            result -= 2 # -2 because of the 2 bytes of the PlanetType PlanetType
            result -= 2 # -2 because of the 2 bytes of the PlanetSize PlanetSize
            result -= 2 # -2 because of the 2 bytes of the short Unknown_18
            result -= 2 # -2 because of the 2 bytes of the ushort PlanetStructureBlockSize
            result -= 2 # -2 because of the 2 bytes of the short PlanetIndex
            result -= 2 # -2 because of the 2 bytes of the short SystemId
            result -= 4 # -4 because of the 4 bytes of the float Z
            result -= 4 # -4 because of the 4 bytes of the float Y
            result -= 4 # -4 because of the 4 bytes of the float X
            result -= 2 # -2 because of the 2 bytes of the short Unknown_0

            self.planet_address = result
        else:
            self.planet_address = self.research_address-0x496f1

        self.adress["Planet"] = self.planet_address

        return self.planet_address


    def get_planet(self, i) -> ascendancy.class_ascendancy.Planet:
        buff = self.dosbox_ascendancy.read_bytes(self.planet_address+i*self.size_struct_planet, self.size_struct_planet)
        planet = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Planet)
        return planet

    def get_all_planets(self) -> list[ascendancy.class_ascendancy.Planet]:
        planets = []
        for i in range(300):
            planets.append(self.get_planet(i))
        return planets

    def set_planet(self, i, planet: ascendancy.class_ascendancy.Planet):
        buff = ascendancy.Struct_to_bytes(planet)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.planet_address+i*self.size_struct_planet, buff, len(buff))

    def set_all_planets(self, planets: list[ascendancy.class_ascendancy.Planet]):
        for i in range(len(planets)):
            self.set_planet(i, planets[i])

    # Ship Address

    
    def get_ship_address(self):
        """Get Ship Address"""
        if self.old_method:
            a_ship_name = b"".join([i.encode() for i in save.Ships[0].Name])

            result = pymem.pattern.pattern_scan_all(self.dosbox_ascendancy.process_handle, a_ship_name)

            result -= 4 # -4 because of the 4 bytes of the int Unknown_54
            result -= 4 # -4 because of the 4 bytes of the int Unknown_50
            result -= 4 # -4 because of the 4 bytes of the int Unknown_46
            result -= 4 # -4 because of the 4 bytes of the int Unknown_42
            result -= 4 # -4 because of the 4 bytes of the int ScannerStrength
            result -= 4 # -4 because of the 4 bytes of the int Unknown_34
            result -= 4 # -4 because of the 4 bytes of the int PowerStrength
            result -= 4 # -4 because of the 4 bytes of the int Unknown_26
            result -= 4 # -4 because of the 4 bytes of the int EngineStrength
            result -= 4 # -4 because of the 4 bytes of the int StarlaneTravelMultiplierRed
            result -= 4 # -4 because of the 4 bytes of the int StarlaneTravelMultiplierBlue
            result -= 4 # -4 because of the 4 bytes of the int ShieldStrength
            result -= 4 # -4 because of the 4 bytes of the int AttackStrength
            result -= 4 # -4 because of the 4 bytes of the int ShipId
            result -= 2 # -2 because of the 2 bytes of the short Unknown_0

            self.ship_address = result
        else:
            self.ship_address = self.research_address-0x3A6B7

        self.adress["Ship"] = self.ship_address

        return self.ship_address

    def get_ship(self, i) -> ascendancy.class_ascendancy.Ship:
        buff = self.dosbox_ascendancy.read_bytes(self.ship_address+i*self.size_struct_ship, self.size_struct_ship)
        ship = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Ship)
        return ship

    def get_all_ships(self) -> list[ascendancy.class_ascendancy.Ship]:
        ships = []
        number_of_ships = self.dosbox_ascendancy.read_int(self.number_of_ships_address)
        for i in range(number_of_ships):
            ships.append(self.get_ship(i))
        return ships

    def set_ship(self, i, ship: ascendancy.class_ascendancy.Ship):
        buff = ascendancy.Struct_to_bytes(ship)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.ship_address+i*self.size_struct_ship, buff, len(buff))

    def set_all_ships(self, ships: list[ascendancy.class_ascendancy.Ship]):
        for i in range(len(ships)):
            self.set_ship(i, ships[i])

    def get_systems_address(self):
        """Get StarSystems Address"""
        if self.old_method:
            a_system_name = b"".join([i.encode() for i in save.StarSystems[0].Name])

            result = pymem.pattern.pattern_scan_all(self.dosbox_ascendancy.process_handle, a_system_name)

            result -= 1 # -1 because of the 1 byte of the byte Unknown_27
            result -= 2 # -2 because of the 2 bytes of the short Unknown_25
            result -= 1 # -1 because of the 1 byte of the byte Unknown_24
            result -= 1 # -1 because of the 1 byte of the byte Unknown_23
            result -= 1 # -1 because of the 1 byte of the byte Unknown_22
            result -= 1 # -1 because of the 1 byte of the char ShipIndicator
            result -= 1 # -1 because of the 1 byte of the byte Uknown_20
            result -= 1 # -1 because of the 1 byte of the byte Uknown_19
            result -= 1 # -1 because of the 1 byte of the byte Uknown_18
            result -= 1 # -1 because of the 1 byte of the byte Uknown_17
            result -= 4 # -4 because of the 4 bytes of the int Z
            result -= 4 # -4 because of the 4 bytes of the int Y
            result -= 4 # -4 because of the 4 bytes of the int X
            result -= 4 # -4 because of the 4 bytes of the int SystemId
            result -= 4 # -4 because of the 4 bytes of the StarType StarType

            self.systems_address = result
        else:
            self.systems_address = self.research_address-0x60b84

        self.adress["StarSystem"] = self.systems_address

        return self.systems_address

    def get_system(self, i) -> ascendancy.class_ascendancy.StarSystem:
        buff = self.dosbox_ascendancy.read_bytes(self.systems_address+i*self.size_struct_systems, self.size_struct_systems)
        system = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.StarSystem)
        return system

    def get_all_systems(self) -> list[ascendancy.class_ascendancy.StarSystem]:
        systems = []
        for i in range(100):
            systems.append(self.get_system(i))
        return systems

    def set_system(self, i, system: ascendancy.class_ascendancy.StarSystem):
        buff = ascendancy.Struct_to_bytes(system)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.systems_address+i*self.size_struct_systems, buff, len(buff))

    def set_all_systems(self, systems: list[ascendancy.class_ascendancy.StarSystem]):
        for i in range(len(systems)):
            self.set_system(i, systems[i])

    def get_diplomacy_address(self):
        """Get Diplomacy Address"""        
        self.diplomacy_address = self.research_address-0x61932

        self.adress["Diplomacy"] = self.diplomacy_address

        return self.diplomacy_address

    def get_diplomacy(self, i) -> ascendancy.class_ascendancy.Diplomacy:
        buff = self.dosbox_ascendancy.read_bytes(self.diplomacy_address+i*self.size_struct_diplomacy, self.size_struct_diplomacy)
        diplomacy = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Diplomacy)
        return diplomacy

    def get_all_diplomacy(self) -> list[ascendancy.class_ascendancy.Diplomacy]:
        diplomacy = []
        for i in range(7):
            diplomacy.append(self.get_diplomacy(i))
        return diplomacy

    def set_diplomacy(self, i, diplomacy: ascendancy.class_ascendancy.Diplomacy):
        buff = ascendancy.Struct_to_bytes(diplomacy)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.diplomacy_address+i*self.size_struct_diplomacy, buff, len(buff))

    def set_all_diplomacy(self, diplomacy: list[ascendancy.class_ascendancy.Diplomacy]):
        for i in range(len(diplomacy)):
            self.set_diplomacy(i, diplomacy[i])

    def get_starlanes_address(self):
        """Get StarLanes Address"""
        self.starlanes_address = self.research_address-0x5E5FC

        self.adress["StarLanes"] = self.starlanes_address

        return self.starlanes_address

    def get_starlanes(self, i) -> ascendancy.class_ascendancy.StarLane:
        buff = self.dosbox_ascendancy.read_bytes(self.starlanes_address+i*self.size_struct_starlanes, self.size_struct_starlanes)
        starlanes = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.StarLane)
        return starlanes

    def get_all_starlanes(self) -> list[ascendancy.class_ascendancy.StarLane]:
        starlanes = []
        for i in range(100):
            starlanes.append(self.get_starlanes(i))
        return starlanes

    def set_starlanes(self, i, starlanes: ascendancy.class_ascendancy.StarLane):
        buff = ascendancy.Struct_to_bytes(starlanes)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.starlanes_address+i*self.size_struct_starlanes, buff, len(buff))

    def set_all_starlanes(self, starlanes: list[ascendancy.class_ascendancy.StarLane]):
        for i in range(len(starlanes)):
            self.set_starlanes(i, starlanes[i])

    def get_current_research_address(self):
        """Get CurrentResearch Address"""
        self.current_research_items_address = self.research_address+0x1D4B

        self.adress["CurrentResearchItems"] = self.current_research_items_address

        return self.current_research_items_address

    def get_current_research_items(self, i) -> int:
        current_research_items = self.dosbox_ascendancy.read_short(self.current_research_items_address+i*self.size_struct_current_research_items, self.size_struct_current_research_items)
        return current_research_items

    def get_all_current_research_items(self) -> list[int]:
        current_research_items = []
        for i in range(7):
            current_research_items.append(self.get_current_research_items(i))
        return current_research_items

    def set_current_research_items(self, i, current_research_items: int):
        self.dosbox_ascendancy.write_short(self.current_research_items_address+i*self.size_struct_current_research_items, current_research_items, self.size_struct_current_research_items)

    def set_all_current_research_items(self, current_research_items: list[int]):
        for i in range(len(current_research_items)):
            self.set_current_research_items(i, current_research_items[i])

    def get_planet_structures_address(self):
        """Get PlanetStructures Address"""
        self.planet_structures_address = self.research_address-0x5CF71

        self.adress["PlanetStructures"] = self.planet_structures_address

        return self.planet_structures_address

    def get_planet_structures(self, i) -> ascendancy.class_ascendancy.PlanetStructure:
        buff = self.dosbox_ascendancy.read_bytes(self.planet_structures_address+i*self.size_struct_planet_structures, self.size_struct_planet_structures)
        planet_structures = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.PlanetStructure)
        return planet_structures

    def get_all_planet_structures(self) -> list[ascendancy.class_ascendancy.PlanetStructure]:
        planet_structures = []
        for i in range(11405):
            planet_structures.append(self.get_planet_structures(i))
        return planet_structures

    def set_planet_structures(self, i, planet_structures: ascendancy.class_ascendancy.PlanetStructure):
        buff = ascendancy.Struct_to_bytes(planet_structures)
        buff = bytes(buff)
        self.dosbox_ascendancy.write_bytes(self.planet_structures_address+i*self.size_struct_planet_structures, buff, len(buff))

    def set_all_planet_structures(self, planet_structures: list[ascendancy.class_ascendancy.PlanetStructure]):
        for i in range(len(planet_structures)):
            self.set_planet_structures(i, planet_structures[i])

    def print_all_adress(self):
        for i,j in sorted(self.adress.items(), key=lambda x: x[1]):
            print(i,hex(j))

    def selected_app(self, chn = "dosbox.exe"):
        self.dosbox_ascendancy = pymem.Pymem(chn)

    def init_address(self):
        self.get_paused_address()
        self.get_number_of_ships_address()
        self.get_research_address()
        self.get_number_of_days_address()
        self.get_number_of_race_address()
        self.get_menu_address()
        self.get_race_address()
        self.get_planet_address()
        self.get_ship_address()
        self.get_systems_address()
        self.get_diplomacy_address()
        self.get_starlanes_address()
        self.get_current_research_address()
        self.get_planet_structures_address()

if __name__ == "__main__":
    # Open last save file
    save = ascendancy.load_save("game/03.SAV")

    game = Game()

    # Open DosBox
    game.selected_app("dosbox.exe")

    # Get all address
    game.init_address()
    game.print_all_adress()
