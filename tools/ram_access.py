import pymem
import ascendancy_lib as ascendancy

# Init addresses

adress = {}

old_method = False

# Paused Address

paused_address = 0
def get_paused_address() -> int:
    """Get Paused Address"""
    global paused_address
    
    result = pymem.pattern.pattern_scan_all(dosbox_ascendancy.process_handle, br"DATA\\SMRACE19\.SHP")

    paused_address = result-0x7E4

    adress["paused"] = paused_address
    return paused_address

# Number of ships Address

number_of_ships_address = 0
number_of_ships = 0
def get_number_of_ships_address() -> int:
    """Get Number of ships Address"""
    global number_of_ships_address, number_of_ships

    number_of_ships_address = paused_address-0x5BC6D

    number_of_ships = dosbox_ascendancy.read_int(number_of_ships_address)

    adress["number of ships"] = number_of_ships_address
    return number_of_ships_address

def get_number_of_ships() -> int:
    """Get Number of ships"""
    global number_of_ships

    number_of_ships = dosbox_ascendancy.read_int(number_of_ships_address)

    return number_of_ships

# Research Address

research_address = 0
size_struct_research = ascendancy.size_of_struct(ascendancy.asc.Model.ResearchItem)
def get_research_address() -> int:
    """Get Research Address"""
    global research_address

    if old_method:
        a_research_name = b"".join([i.encode() for i in save.ResearchItems[0].Name])

        result = pymem.pattern.pattern_scan_all(dosbox_ascendancy.process_handle, a_research_name)

        research_address = result
    else:
        a_research_name = b"Orbital Structures"

        result = pymem.pattern.pattern_scan_all(dosbox_ascendancy.process_handle, a_research_name)

        research_address = result

    adress["ResearchItem"] = research_address

    return research_address

def get_research(i) -> ascendancy.class_ascendancy.ResearchItem:
    buff = dosbox_ascendancy.read_bytes(research_address+i*size_struct_research, size_struct_research)
    research = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Enum.ResearchItem)
    return research

def get_all_research() -> list[ascendancy.class_ascendancy.ResearchItem]:
    l = []
    for i in range(66):
        l.append(get_research(i))
    return l

def set_research(i, research: ascendancy.class_ascendancy.ResearchItem):
    buff = ascendancy.Struct_to_bytes(research)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(research_address+i*size_struct_research, buff, size_struct_research)

def set_all_research(research_list: list[ascendancy.class_ascendancy.ResearchItem]):
    for i in range(len(research_list)):
        set_research(i, research_list[i])

# Days Address

days_address = 0
def get_number_of_days_address():
    """Get Number of days Address"""
    global days_address

    days_address = research_address-0x61936

    adress["Days"] = days_address

    return days_address

def get_number_of_days() -> int:
    """Get Number of days"""

    days = dosbox_ascendancy.read_int(days_address)

    return days

def set_number_of_days(days: int):
    """Set Number of days"""

    dosbox_ascendancy.write_int(days_address, days)

# Number of race Address

race_number_address = 0
def get_number_of_race_address():
    """Get Number of race Address"""
    global race_number_address

    race_number_address = research_address-0x60BAE

    adress["race number"] = race_number_address

    return race_number_address

# Menu on screen Address

menu_address = 0
def get_menu_address():
    """Get Menu on screen Address"""
    global menu_address

    menu_address = research_address+0x9E3E

    adress["Menu"] = menu_address

    return menu_address

# Race Address

race_address = 0
def get_race_address():
    """Get Race Address"""
    global race_address

    race_address = research_address+0x327D6

    adress["Race"] = race_address

    return race_address

def get_race(i) -> ascendancy.class_ascendancy.Race:
    buff = dosbox_ascendancy.read_bytes(race_address+i*0x4, 0x4)
    race = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Enum.Race)
    return race

def get_all_race() -> list[ascendancy.class_ascendancy.Race]:
    l = []
    for i in range(7):
        l.append(get_race(i))
    return l

def set_race(i, race: ascendancy.class_ascendancy.Race):
    buff = ascendancy.Struct_to_bytes(race)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(race_address+i*0x4, buff, 0x4)

def set_all_race(races: list[ascendancy.class_ascendancy.Race]):
    for i in range(7):
        set_race(i,races[i])

# Planet Address

planet_address = 0
size_struct_planet = ascendancy.size_of_struct(ascendancy.asc.Model.Planet)
def get_planet_address():
    """Get Planet Address"""
    global planet_address

    if old_method:
        a_planet_name = b"".join([i.encode() for i in save.Planets[0].Name])

        result = pymem.pattern.pattern_scan_all(dosbox_ascendancy.process_handle, a_planet_name)

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

        planet_address = result
    else:
        planet_address = research_address-0x496f1

    adress["Planet"] = planet_address

    return planet_address


def get_planet(i) -> ascendancy.class_ascendancy.Planet:
    buff = dosbox_ascendancy.read_bytes(planet_address+i*size_struct_planet, size_struct_planet)
    planet = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Planet)
    return planet

def get_all_planets() -> list[ascendancy.class_ascendancy.Planet]:
    planets = []
    for i in range(300):
        planets.append(get_planet(i))
    return planets

def set_planet(i, planet: ascendancy.class_ascendancy.Planet):
    buff = ascendancy.Struct_to_bytes(planet)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(planet_address+i*size_struct_planet, buff, len(buff))

def set_all_planets(planets: list[ascendancy.class_ascendancy.Planet]):
    for i in range(len(planets)):
        set_planet(i, planets[i])

# Ship Address

ship_address = 0
size_struct_ship = ascendancy.size_of_struct(ascendancy.asc.Model.Ship)-4 # maybe the -4 is for the index
def get_ship_address():
    """Get Ship Address"""
    global ship_address

    if old_method:
        a_ship_name = b"".join([i.encode() for i in save.Ships[0].Name])

        result = pymem.pattern.pattern_scan_all(dosbox_ascendancy.process_handle, a_ship_name)

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

        ship_address = result
    else:
        ship_address = research_address-0x3A6B7

    adress["Ship"] = ship_address

    return ship_address

def get_ship(i) -> ascendancy.class_ascendancy.Ship:
    buff = dosbox_ascendancy.read_bytes(ship_address+i*size_struct_ship, size_struct_ship)
    ship = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Ship)
    return ship

def get_all_ships() -> list[ascendancy.class_ascendancy.Ship]:
    ships = []
    number_of_ships = dosbox_ascendancy.read_int(number_of_ships_address)
    for i in range(number_of_ships):
        ships.append(get_ship(i))
    return ships

def set_ship(i, ship: ascendancy.class_ascendancy.Ship):
    buff = ascendancy.Struct_to_bytes(ship)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(ship_address+i*size_struct_ship, buff, len(buff))

def set_all_ships(ships: list[ascendancy.class_ascendancy.Ship]):
    for i in range(len(ships)):
        set_ship(i, ships[i])

adress["number_of_ships"] = number_of_ships_address

# StarSystems Address

systems_address = 0
size_struct_systems = ascendancy.size_of_struct(ascendancy.asc.Model.StarSystem)
def get_systems_address():
    """Get StarSystems Address"""
    global systems_address

    if old_method:
        a_system_name = b"".join([i.encode() for i in save.StarSystems[0].Name])

        result = pymem.pattern.pattern_scan_all(dosbox_ascendancy.process_handle, a_system_name)

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

        systems_address = result
    else:
        systems_address = research_address-0x60b84

    adress["StarSystem"] = systems_address

    return systems_address

def get_system(i) -> ascendancy.class_ascendancy.StarSystem:
    buff = dosbox_ascendancy.read_bytes(systems_address+i*size_struct_systems, size_struct_systems)
    system = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.StarSystem)
    return system

def get_all_systems() -> list[ascendancy.class_ascendancy.StarSystem]:
    systems = []
    for i in range(100):
        systems.append(get_system(i))
    return systems

def set_system(i, system: ascendancy.class_ascendancy.StarSystem):
    buff = ascendancy.Struct_to_bytes(system)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(systems_address+i*size_struct_systems, buff, len(buff))

def set_all_systems(systems: list[ascendancy.class_ascendancy.StarSystem]):
    for i in range(len(systems)):
        set_system(i, systems[i])

# Diplomacy Address

diplomacy_address = 0
size_struct_diplomacy = ascendancy.size_of_struct(ascendancy.asc.Model.Diplomacy)
def get_diplomacy_address():
    """Get Diplomacy Address"""
    global diplomacy_address
    
    diplomacy_address = research_address-0x61932

    adress["Diplomacy"] = diplomacy_address

    return diplomacy_address

def get_diplomacy(i) -> ascendancy.class_ascendancy.Diplomacy:
    buff = dosbox_ascendancy.read_bytes(diplomacy_address+i*size_struct_diplomacy, size_struct_diplomacy)
    diplomacy = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.Diplomacy)
    return diplomacy

def get_all_diplomacy() -> list[ascendancy.class_ascendancy.Diplomacy]:
    diplomacy = []
    for i in range(7):
        diplomacy.append(get_diplomacy(i))
    return diplomacy

def set_diplomacy(i, diplomacy: ascendancy.class_ascendancy.Diplomacy):
    buff = ascendancy.Struct_to_bytes(diplomacy)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(diplomacy_address+i*size_struct_diplomacy, buff, len(buff))

def set_all_diplomacy(diplomacy: list[ascendancy.class_ascendancy.Diplomacy]):
    for i in range(len(diplomacy)):
        set_diplomacy(i, diplomacy[i])

# StarLanes Address

starlanes_address = 0
size_struct_starlanes = ascendancy.size_of_struct(ascendancy.asc.Model.StarLane)
def get_starlanes_address():
    """Get StarLanes Address"""
    global starlanes_address
    
    starlanes_address = research_address-0x5E5FC

    adress["StarLanes"] = starlanes_address

    return starlanes_address

def get_starlanes(i) -> ascendancy.class_ascendancy.StarLane:
    buff = dosbox_ascendancy.read_bytes(starlanes_address+i*size_struct_starlanes, size_struct_starlanes)
    starlanes = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.StarLane)
    return starlanes

def get_all_starlanes() -> list[ascendancy.class_ascendancy.StarLane]:
    starlanes = []
    for i in range(100):
        starlanes.append(get_starlanes(i))
    return starlanes

def set_starlanes(i, starlanes: ascendancy.class_ascendancy.StarLane):
    buff = ascendancy.Struct_to_bytes(starlanes)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(starlanes_address+i*size_struct_starlanes, buff, len(buff))

def set_all_starlanes(starlanes: list[ascendancy.class_ascendancy.StarLane]):
    for i in range(len(starlanes)):
        set_starlanes(i, starlanes[i])

# CurrentResearch Address

current_research_items_address = 0
size_struct_current_research_items = 2 # short
def get_current_research_address():
    """Get CurrentResearch Address"""
    global current_research_items_address
    
    current_research_items_address = research_address+0x1D4B

    adress["CurrentResearchItems"] = current_research_items_address

    return current_research_items_address

def get_current_research_items(i) -> int:
    current_research_items = dosbox_ascendancy.read_short(current_research_items_address+i*size_struct_current_research_items, size_struct_current_research_items)
    return current_research_items

def get_all_current_research_items() -> list[int]:
    current_research_items = []
    for i in range(7):
        current_research_items.append(get_current_research_items(i))
    return current_research_items

def set_current_research_items(i, current_research_items: int):
    dosbox_ascendancy.write_short(current_research_items_address+i*size_struct_current_research_items, current_research_items, size_struct_current_research_items)

def set_all_current_research_items(current_research_items: list[int]):
    for i in range(len(current_research_items)):
        set_current_research_items(i, current_research_items[i])

# PlanetStructures Address

planet_structures_address = 0
size_struct_planet_structures = ascendancy.size_of_struct(ascendancy.asc.Model.PlanetStructure)
def get_planet_structures_address():
    """Get PlanetStructures Address"""
    global planet_structures_address
    
    planet_structures_address = research_address-0x5CF71

    adress["PlanetStructures"] = planet_structures_address

    return planet_structures_address

def get_planet_structures(i) -> ascendancy.class_ascendancy.PlanetStructure:
    buff = dosbox_ascendancy.read_bytes(planet_structures_address+i*size_struct_planet_structures, size_struct_planet_structures)
    planet_structures = ascendancy.bytes_to_Struct(buff, ascendancy.asc.Model.PlanetStructure)
    return planet_structures

def get_all_planet_structures() -> list[ascendancy.class_ascendancy.PlanetStructure]:
    planet_structures = []
    for i in range(11405):
        planet_structures.append(get_planet_structures(i))
    return planet_structures

def set_planet_structures(i, planet_structures: ascendancy.class_ascendancy.PlanetStructure):
    buff = ascendancy.Struct_to_bytes(planet_structures)
    buff = bytes(buff)
    dosbox_ascendancy.write_bytes(planet_structures_address+i*size_struct_planet_structures, buff, len(buff))

def set_all_planet_structures(planet_structures: list[ascendancy.class_ascendancy.PlanetStructure]):
    for i in range(len(planet_structures)):
        set_planet_structures(i, planet_structures[i])

def print_all_adress():
    for i,j in sorted(adress.items(), key=lambda x: x[1]):
        print(i,hex(j))

def selected_app(chn = "dosbox.exe"):
    global dosbox_ascendancy
    dosbox_ascendancy = pymem.Pymem(chn)

def init_address():
    get_paused_address()
    get_number_of_ships_address()
    get_research_address()
    get_number_of_days_address()
    get_number_of_race_address()
    get_menu_address()
    get_race_address()
    get_planet_address()
    get_ship_address()
    get_systems_address()
    get_diplomacy_address()
    get_starlanes_address()
    get_current_research_address()
    get_planet_structures_address()

if __name__ == "__main__":
    # Open last save file
    save = ascendancy.load_save("game/03.SAV")

    # Open DosBox
    selected_app("dosbox.exe")

    # Get all address
    init_address()
    print_all_adress()
