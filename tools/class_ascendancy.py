from dataclasses import dataclass
from enum import Enum

"""
public enum WinMechanism : int
    {
        InProgress = 0,
        Extinct,
        MilitaryVictory,
        HomeworldVictory,
        AllianceVictory,
        MassiveVictory,
    }
"""

class WinMechanism(Enum):
    InProgress = 0
    Extinct = 1
    MilitaryVictory = 2
    HomeworldVictory = 3
    AllianceVictory = 4
    MassiveVictory = 5

"""
public enum Race : int
    {
        Minions,
        Snovemdomas,
        Orfa,
        Kambuchka,
        Hanshaks,
        Fludentri,
        Baliflids,
        Swaparamans,
        Frutmaka,
        Shevar,
        Govorom,
        Ungooma,
        Dubtaks,
        Capelons,
        Mebes,
        Oculons,
        Arbryls,
        Marmosians,
        Chronomyst,
        Chamachies,
        Nimbuloids
    }
"""

class Race(Enum):
    Minions = 0
    Snovemdomas = 1
    Orfa = 2
    Kambuchka = 3
    Hanshaks = 4
    Fludentri = 5
    Baliflids = 6
    Swaparamans = 7
    Frutmaka = 8
    Shevar = 9
    Govorom = 10
    Ungooma = 11
    Dubtaks = 12
    Capelons = 13
    Mebes = 14
    Oculons = 15
    Arbryls = 16
    Marmosians = 17
    Chronomyst = 18
    Chamachies = 19
    Nimbuloids = 20

"""
public class Header
    {
        public int CurrentDay_LoadScreen; // 0
        public int RaceCount; // 4
        public int Unknown_8; // 8 Always 0
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 7)]
        public Race[] Race; // 12
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 7)]
        public int[] Colour; // 40
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 44)]
        public byte[] Unknown_68; // 68
        public int SaveGameIndex; // 113 0-indexed
        public int ResearchBlockSize; // 117 i.e. 7538 (includes 2 byes for item count)
        public int StarSystemSize; // 121 i.e. 96
        public int PlanetSize; // 125 i.e. 123
        public int DiplomacySize; // 129 i.e 494
        public int StarLaneSize; // 133 i.e 39
        public int Unknown_137; // 137 Unknown size? always 414
        public int Unknown_141; // 141 Unknown size? always 13
        public int Unknown_145; // 145 Unknown size? always 218351
        public int CurrentDay_InGame; // 149
        public int LastStarSystemDisplayed; // 153 Index into StarSystem
        public int LastPlanetDisplayed; // 157 Index into Planet
        public WinMechanism WinMechanism; // 161
        public int VictoryPercentage; // 165
        public int Unknown_169; // Usually same as Unknown_177
        public int Unknown_173; // Often same as Unknown_177 / Unknown_169
        public int Unknown_177; // Usually same as Unknown_169
    }
"""

@dataclass
class Header:
    CurrentDay_LoadScreen: int
    RaceCount: int
    Unknown_8: int # selected Race
    Race: list[Race]
    Colour: list
    Unknown_68: list
    SaveGameIndex: int
    ResearchBlockSize: int
    StarSystemSize: int
    PlanetSize: int
    DiplomacySize: int
    StarLaneSize: int
    Unknown_137: int
    Unknown_141: int
    Unknown_145: int
    CurrentDay_InGame: int
    LastStarSystemDisplayed: int
    LastPlanetDisplayed: int
    WinMechanism: WinMechanism
    VictoryPercentage: int
    Unknown_169: int
    Unknown_173: int
    Unknown_177: int

"""
public enum ResearchableItem : byte
    {
        Orbital_Structures = 0,
        Interplanetary_Exploration,
        Tonklin_Diary,
        Spacetime_Surfing,
        Superconductivity,
        Environmental_Encapsulation,
        Xenobiology,
        Spectral_Analysis,
        Advanced_Interferometry,
        Power_Conversion,
        Advanced_Chemistry,
        Momentum_Deconservation,
        Gravity_Control,
        Molecular_Explosives,
        Hyperlogic,
        Cloaking,
        Gravimetrics,
        Strong_Force_Weakening,
        Light_Bending,
        Advanced_Exploration,
        Diplomatics,
        Mass_Phasing,
        Positron_Guidance,
        Gravimetric_Combustion,
        EM_Field_Coupling,
        Subatomics,
        Planetary_Replenishment,
        Momentum_Reflection,
        Hyperradiation,
        Plasmatics,
        Energy_Redirection,
        Large_Scale_Construction,
        Level_Logic,
        Star_Lane_Anatomy,
        Stasis_Field_Science,
        Coherent_Photonics,
        Superstring_Compression,
        Murgatroyd_Hypothesis,
        Matter_Duplication,
        Energy_Focusing,
        Scientific_Sorcery,
        Advanced_Fun_Techniques,
        Repulsion_Beam_Tech,
        Hyperwave_Technology,
        Fergnatzs_Last_Theorem,
        Thought_Analysis,
        Inertial_Control,
        Nanoenergons,
        Hypergeometry,
        Teleinfiltration,
        Hyperdrive_Technology,
        Microbotics,
        Ecosphere_Phase_Control,
        Hyperwave_Emission_Control,
        Nanopropulsion,
        Nanodeflection,
        Nanofocusing,
        Doom_Mechanization,
        Snooping,
        Megagraph_Theory,
        Self_Modifying_Structures,
        Advanced_Planetary_Armaments,
        Accel_Energy_Replenishment,
        Gravity_Flow_Control,
        Action_At_A_Distance,
        Illusory_Machinations,

        End = 255,
    }
"""

class ResearchableItem(Enum):
    Orbital_Structures = 0
    Interplanetary_Exploration = 1
    Tonklin_Diary = 2
    Spacetime_Surfing = 3
    Superconductivity = 4
    Environmental_Encapsulation = 5
    Xenobiology = 6
    Spectral_Analysis = 7
    Advanced_Interferometry = 8
    Power_Conversion = 9
    Advanced_Chemistry = 10
    Momentum_Deconservation = 11
    Gravity_Control = 12
    Molecular_Explosives = 13
    Hyperlogic = 14
    Cloaking = 15
    Gravimetrics = 16
    Strong_Force_Weakening = 17
    Light_Bending = 18
    Advanced_Exploration = 19
    Diplomatics = 20
    Mass_Phasing = 21
    Positron_Guidance = 22
    Gravimetric_Combustion = 23
    EM_Field_Coupling = 24
    Subatomics = 25
    Planetary_Replenishment = 26
    Momentum_Reflection = 27
    Hyperradiation = 28
    Plasmatics = 29
    Energy_Redirection = 30
    Large_Scale_Construction = 31
    Level_Logic = 32
    Star_Lane_Anatomy = 33
    Stasis_Field_Science = 34
    Coherent_Photonics = 35
    Superstring_Compression = 36
    Murgatroyd_Hypothesis = 37
    Matter_Duplication = 38
    Energy_Focusing = 39
    Scientific_Sorcery = 40
    Advanced_Fun_Techniques = 41
    Repulsion_Beam_Tech = 42
    Hyperwave_Technology = 43
    Fergnatzs_Last_Theorem = 44
    Thought_Analysis = 45
    Inertial_Control = 46
    Nanoenergons = 47
    Hypergeometry = 48
    Teleinfiltration = 49
    Hyperdrive_Technology = 50
    Microbotics = 51
    Ecosphere_Phase_Control = 52
    Hyperwave_Emission_Control = 53
    Nanopropulsion = 54
    Nanodeflection = 55
    Nanofocusing = 56
    Doom_Mechanization = 57
    Snooping = 58
    Megagraph_Theory = 59
    Self_Modifying_Structures = 60
    Advanced_Planetary_Armaments = 61
    Accel_Energy_Replenishment = 62
    Gravity_Flow_Control = 63
    Action_At_A_Distance = 64
    Illusory_Machinations = 65

    End = 255

"""
public class ResearchItem
    {
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 60)]
        public char[] Name; // 0
        public ushort ResearchTime; // 60
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 5)]
        public ResearchableItem[] Requires; // 62
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 5)]
        public ResearchableItem[] RequiredBy; // 67
        public byte KnownBy; // 72 Bitmask
        public byte PendingAcknowledgement; // 73 Bitmask. Set to 1 when discovered, set to 0 when research screen opened
        public byte Unknown_74; // 74 Always 0
    }
"""

@dataclass
class ResearchItem:
    Name: list[str]
    ResearchTime: int
    Requires: list[ResearchableItem]
    RequiredBy: list[ResearchableItem]
    KnownBy: int
    PendingAcknowledgement: int
    Unknown_74: int


"""
public enum ManagementType : int
    {
        // 0xFFFFFFFF = no, 0x00000000 = yes
        PlayerManaged = 0,
        AiManaged = -1
    }
"""

class ManagementType(Enum):
    PlayerManaged: int = 0
    AiManaged: int = -1

"""
public enum StarType : byte
    {
        Blue_Giant = 0,
        Pink_Red_Giant,
        Red_Giant,
        Orange_Giant,
        Blue_Medium,
        White_Medium,
        Yellow_Medium,
        Light_Yellow_Medium,
        Orange_Medium,
        Pink_Red_Medium,
        Blue_Dwarf,
        White_Dwarf,
        Red_Dwarf
    }
"""

class StarType(Enum):
    Blue_Giant = 0
    Pink_Red_Giant = 1
    Red_Giant = 2
    Orange_Giant = 3
    Blue_Medium = 4
    White_Medium = 5
    Yellow_Medium = 6
    Light_Yellow_Medium = 7
    Orange_Medium = 8
    Pink_Red_Medium = 9
    Blue_Dwarf = 10
    White_Dwarf = 11
    Red_Dwarf = 12

"""
public class StarSystem
    {
        public StarType StarType; // 0
        public int SystemId; // 1
        public int X; // 5
        public int Y; // 9
        public int Z; // 13
        public byte Unknown_17; // 17
        public byte Unknown_18; // 18
        public byte Unknown_19; // 19 - planatary indicator (rings), set high bit to indicate home world (TODO: of who)
        public byte Unknown_20; // 20
        public char ShipIndicator; // 21 - bitmask of player indices
        public byte Unknown_22; // 22
        public byte Unknown_23; // 23
        public byte Unknown_24; // 24
        public short Unknown_25; // 25
        public byte Unknown_27; // 27
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 12)]
        public char[] Name; // 28
        public int Unknown_40; // 40 Always 0
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 24)]
        public byte[] Unknown_44; // 44
        public short StarLaneCount; // 68
        public ushort SizeOfPlanetBlock; // 70 i.e. sizeOf(Planet) * planet count ?
        public short Unknown_72; // 72 Always 34 or 35
        public ushort SizeOfPlanetBlock_2; // 74 i.e. sizeOf(Planet) * (planet count + 1) ?
        public short Unknown_76; // 76 Always 34 or 35
        public ushort SizeOfPlanetBlock_3; // 78 i.e. sizeOf(Planet) * planet count ?
        public short Unknown_80; // 80 Always 34 or 35
        public ushort SizeOfPlanetBlock_4; // 82 i.e. sizeOf(Planet) * planet count ?
        public short Unknown_84; // 84 Always 34 or 35
        public ushort SizeOfPlanetBlock_5; // 86 i.e. sizeOf(Planet) * planet count ?
        public short Unknown_88; // 86 Always 34 or 35
        public short PlanetCount; // 90
        public int Unknown_92; // 92  Always 0xffffffff
    }
"""

@dataclass
class StarSystem:
    StarType: StarType
    SystemId: int
    X: int
    Y: int
    Z: int
    Unknown_17: int
    Unknown_18: int
    Unknown_19: int
    Unknown_20: int
    ShipIndicator: str
    Unknown_22: int
    Unknown_23: int
    Unknown_24: int
    Unknown_25: int
    Unknown_27: int
    Name: list[str]
    Unknown_40: int
    Unknown_44: list
    StarLaneCount: int
    SizeOfPlanetBlock: int
    Unknown_72: int
    SizeOfPlanetBlock_2: int
    Unknown_76: int
    SizeOfPlanetBlock_3: int
    Unknown_80: int
    SizeOfPlanetBlock_4: int
    Unknown_84: int
    SizeOfPlanetBlock_5: int
    Unknown_88: int
    PlanetCount: int
    Unknown_92: int

"""
public enum SquareType : byte
    {
        Black = 0,
        White,
        Red,
        Green,
        Blue
    }
"""

class SquareType(Enum):
    Black = 0
    White = 1
    Red = 2
    Green = 3
    Blue = 4

"""
public enum Structure : byte
    {
        Factory = 0,
        Agriplot,
        Laboratory,
        Habitat,
        Metroplex,
        Colony_Base,
        Industrial_Megafacility,
        Artificial_Hydroponifer,
        Research_Campus,
        Logic_Factory,
        Engineering_Retreat,
        Surface_Cloaker,
        Hyperpower_Plant,
        Fertilization_Plant,
        Internet,
        Cloning_Plant,
        Observation_Installation,
        Tractor_Beam,
        Surface_Shield,
        Surface_Mega_Shield,
        Outpost,
        Transport_Tubes,
        Shipyard,
        Ship,
        Orbital_Docks,
        Orbital_Cloaker,
        Orbital_Shield,
        Orbital_Mega_Shield,
        Orbital_Missile_Base,
        Short_Range_Orbital_Whopper,
        Long_Range_Orbital_Whopper,
        Alien_Hospitality,
        Interstellar_Trucking,
        Endless_Party,
        Scientist_Takeover,
        Automation,
        Terraforming,
        Lush_Growth_Bomb,
        Xeno_Archeological_Dig,

        None = 255
    }
"""

class Structure(Enum):
    Factory = 0
    Agriplot = 1
    Laboratory = 2
    Habitat = 3
    Metroplex = 4
    Colony_Base = 5
    Industrial_Megafacility = 6
    Artificial_Hydroponifer = 7
    Research_Campus = 8
    Logic_Factory = 9
    Engineering_Retreat = 10
    Surface_Cloaker = 11
    Hyperpower_Plant = 12
    Fertilization_Plant = 13
    Internet = 14
    Cloning_Plant = 15
    Observation_Installation = 16
    Tractor_Beam = 17
    Surface_Shield = 18
    Surface_Mega_Shield = 19
    Outpost = 20
    Transport_Tubes = 21
    Shipyard = 22
    Ship = 23
    Orbital_Docks = 24
    Orbital_Cloaker = 25
    Orbital_Shield = 26
    Orbital_Mega_Shield = 27
    Orbital_Missile_Base = 28
    Short_Range_Orbital_Whopper = 29
    Long_Range_Orbital_Whopper = 30
    Alien_Hospitality = 31
    Interstellar_Trucking = 32
    Endless_Party = 33
    Scientist_Takeover = 34
    Automation = 35
    Terraforming = 36
    Lush_Growth_Bomb = 37
    Xeno_Archeological_Dig = 38
    None_ = 255

"""
public class PlanetStructure
    {
        public SquareType SquareType;
        public Structure StructureId;
        public byte Complete; //  0 - no, 1 - yes
        public byte Special; // Special

        // Special:
        //  For ships this is the ship index
        //  For shields this is the shield strength (orbital shield = 15, orbital mega shield = 35)
        //  For planetary defences attack strength (orbital missile base = 1, short range whopper = 3)
    }
"""

@dataclass
class PlanetStructure:
    SquareType: SquareType
    StructureId: Structure
    Complete: int
    Special: int

"""
public enum PlanetSize : short
    {
        Tiny = 0,
        Small,
        Medium,
        Large,
        Enormous
    }
"""

class PlanetSize(Enum):
    Tiny = 0
    Small = 1
    Medium = 2
    Large = 3
    Enormous = 4

"""
public enum PlanItem : byte
    {
        Factory = 0,
        Agriplot,
        Laboratory,
        Habitat,
        Metroplex,
        Colony_Base,
        Industrial_Megafacility,
        Artificial_Hydroponifer,
        Research_Campus,
        Logic_Factory,
        Engineering_Retreat,
        Surface_Cloaker,
        Hyperpower_Plant,
        Fertilization_Plant,
        Internet,
        Cloning_Plant,
        Observation_Installation,
        Tractor_Beam,
        Surface_Shield,
        Surface_Mega_Shield,
        Outpost,
        Transport_Tubes,
        Shipyard,
        Ship,
        Orbital_Docks,
        Orbital_Cloaker,
        Orbital_Shield,
        Orbital_Mega_Shield,
        Orbital_Missile_Base,
        Short_Range_Orbital_Whopper,
        Long_Range_Orbital_Whopper,
        Alien_Hospitality,
        Interstellar_Trucking,
        Endless_Party,
        Scientist_Takeover,
        Automation,
        Terraforming,
        Lush_Growth_Bomb,
        Xeno_Archeological_Dig,

        None = 255,
    }
"""

class PlanItem(Enum):
    Factory = 0
    Agriplot = 1
    Laboratory = 2
    Habitat = 3
    Metroplex = 4
    Colony_Base = 5
    Industrial_Megafacility = 6
    Artificial_Hydroponifer = 7
    Research_Campus = 8
    Logic_Factory = 9
    Engineering_Retreat = 10
    Surface_Cloaker = 11
    Hyperpower_Plant = 12
    Fertilization_Plant = 13
    Internet = 14
    Cloning_Plant = 15
    Observation_Installation = 16
    Tractor_Beam = 17
    Surface_Shield = 18
    Surface_Mega_Shield = 19
    Outpost = 20
    Transport_Tubes = 21
    Shipyard = 22
    Ship = 23
    Orbital_Docks = 24
    Orbital_Cloaker = 25
    Orbital_Shield = 26
    Orbital_Mega_Shield = 27
    Orbital_Missile_Base = 28
    Short_Range_Orbital_Whopper = 29
    Long_Range_Orbital_Whopper = 30
    Alien_Hospitality = 31
    Interstellar_Trucking = 32
    Endless_Party = 33
    Scientist_Takeover = 34
    Automation = 35
    Terraforming = 36
    Lush_Growth_Bomb = 37
    Xeno_Archeological_Dig = 38
    None_ = 255

"""
public enum PlanetType : short
    {
        Husk = 0,
        Primordial,
        Congenial,
        Eden,
        Mineral,
        Supermineral,
        Chapel,
        Cathedral,
        Special,
        Tycoon,
        Cornucopia
    }
"""

class PlanetType(Enum):
    Husk = 0
    Primordial = 1
    Congenial = 2
    Eden = 3
    Mineral = 4
    Supermineral = 5
    Chapel = 6
    Cathedral = 7
    Special = 8
    Tycoon = 9
    Cornucopia = 10

"""
public class Planet
    {
        public short Unknown_0; // Always 0
        public float X; // 2150 is edge of system
        public float Y; // Always 0 (-ve values move upwards)
        public float Z;
        public short SystemId;
        public short PlanetIndex; // e.g. Sol I -> 1, Sol II -> 2, Sol III -> 3
        public ushort PlanetStructureBlockSize; // i.e. TotalSquareCount * sizeof(PlanetStructure), tiny = 68, small = 84, medium = 132, large = 220, enormous = 332
        public short Unknown_18; // Always 33 ?
        public PlanetSize PlanetSize;
        public PlanetType PlanetType;
        public short PlanetSquareCount; // Number of planet squares
        public short TotalSquareCount; // Number of total squares
        public short FreeSquareCount; // Number of free squares
        public short OrbitalSquareCount; // Number of space squares
        public short BlackSquareCount; // Number of black squares
        public short Unknown_34; // Always 0?
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 30)]
        public char[] Name;
        public short CurrentPopulation;
        public short Industry;
        public short Research;
        public short Prosperity;
        public short MaximumPopulationCurrent;
        public short UsedPopulation;
        public short PopulationGrowthDiscount; // Subtract this from the growth rate (i.e. 50) to determine when population will next grow
        public short DaysRemainingOnCurrentProject;
        public short CurrentProjectSquare;
        public PlanItem CurrentProject;
        public short MaximumPopulationBase;
        public byte OwnerRaceIndex; // 0xff = no-one
        public short ShieldStrength; // i.e. (Planetary shield count * 256) + (Orbital shield count * 258)
        public ManagementType ManagementType;
        public int Unknown_102; // Always 0 ?
        public int Unknown_106; // Always 0 ?
        public byte XenoarcheologicalRuins; // 0 - no, 2 - yes
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 18)]
        public byte[] Unknown_108;
    }
"""

@dataclass
class Planet:
    Unknown_0: int
    X: float
    Y: float
    Z: float
    SystemId: int
    PlanetIndex: int
    PlanetStructureBlockSize: int
    Unknown_18: int
    PlanetSize: PlanetSize
    PlanetType: PlanetType
    PlanetSquareCount: int
    TotalSquareCount: int
    FreeSquareCount: int
    OrbitalSquareCount: int
    BlackSquareCount: int
    Unknown_34: int
    Name: list[str]
    CurrentPopulation: int
    Industry: int
    Research: int
    Prosperity: int
    MaximumPopulationCurrent: int
    UsedPopulation: int
    PopulationGrowthDiscount: int
    DaysRemainingOnCurrentProject: int
    CurrentProjectSquare: int
    CurrentProject: PlanItem
    MaximumPopulationBase: int
    OwnerRaceIndex: int
    ShieldStrength: int
    ManagementType: ManagementType
    Unknown_102: int
    Unknown_106: int
    XenoarcheologicalRuins: int
    Unknown_108: int

"""
public enum GizmoType : byte
    {
        MassBarrageGun = 0,
        FourierMissiles,
        QuantumSingularityLauncher,
        MolecularDisassociator,
        ElectromagneticPulser,
        Plasmatron,
        Ueberlaser,
        FergnatzLens,
        HypersphereDriver,
        Nanomanipulator,
        IonWrap,
        ConcussionShield,
        WaveScatterer,
        Deactotron,
        HyperwaveNullifier,
        Nanoshell,
        TonklinMotor,
        IonBanger,
        GravitonProjector,
        InertiaNegator,
        NanowaveSpaceBender,
        TonklinFrequencyAnalyzer,
        SubspacePhaseArray,
        AuralCloudConstructor,
        HyperwaveTympanum,
        MurgatroydsKnower,
        NanowaveDecouplingNet,
        ProtonShaver,
        SubatomicScoop,
        QuarkExpress,
        VanCreegHypersplicer,
        Nanotwirler,
        LaneBlocker,
        MolecularTieDown,
        IntellectScrambler,
        BrunswikDissipator,
        Recaller,
        Disarmer,
        SmartBomb,
        GravityDistorter,
        FleetDisperser,
        XRayMegaglasses,
        Cloaker,
        StarLaneDrive,
        StarLaneHyperdrive,
        PositronBouncer,
        GravimetricCatapult,
        MyrmidonicCarbonizer,
        ContainmentDevice,
        ShieldBlaster,
        Backfirer,
        LaneDestabilizer,
        TractorBeam,
        Cannibalizer,
        MovingPartExploiter,
        Hyperswapper,
        GravimetricCondensor,
        Accutron,
        RemoteRepairFacility,
        SacrificialOrb,
        LaneMagnetron,
        Disintegrator,
        LaneEndoscope,
        ToroidalBlaster,
        Gizmogrifier,
        Replenisher,
        SpecialtyBlaster,
        GyroInductor,
        PlasmaCoupler,
        Invulnerablizer,
        PhaseBomb,
        Colonizer,
        SelfDestructotron,
        InvasionModule,
        MassCondensor,
        Hyperfuel,

        None = 255
    }
"""

class GizmoType(Enum):
    MassBarrageGun = 0
    FourierMissiles = 1
    QuantumSingularityLauncher = 2
    MolecularDisassociator = 3
    ElectromagneticPulser = 4
    Plasmatron = 5
    Ueberlaser = 6
    FergnatzLens = 7
    HypersphereDriver = 8
    Nanomanipulator = 9
    IonWrap = 10
    ConcussionShield = 11
    WaveScatterer = 12
    Deactotron = 13
    HyperwaveNullifier = 14
    Nanoshell = 15
    TonklinMotor = 16
    IonBanger = 17
    GravitonProjector = 18
    InertiaNegator = 19
    NanowaveSpaceBender = 20
    TonklinFrequencyAnalyzer = 21
    SubspacePhaseArray = 22
    AuralCloudConstructor = 23
    HyperwaveTympanum = 24
    MurgatroydsKnower = 25
    NanowaveDecouplingNet = 26
    ProtonShaver = 27
    SubatomicScoop = 28
    QuarkExpress = 29
    VanCreegHypersplicer = 30
    Nanotwirler = 31
    LaneBlocker = 32
    MolecularTieDown = 33
    IntellectScrambler = 34
    BrunswikDissipator = 35
    Recaller = 36
    Disarmer = 37
    SmartBomb = 38
    GravityDistorter = 39
    FleetDisperser = 40
    XRayMegaglasses = 41
    Cloaker = 42
    StarLaneDrive = 43
    StarLaneHyperdrive = 44
    PositronBouncer = 45
    GravimetricCatapult = 46
    MyrmidonicCarbonizer = 47
    ContainmentDevice = 48
    ShieldBlaster = 49
    Backfirer = 50
    LaneDestabilizer = 51
    TractorBeam = 52
    Cannibalizer = 53
    MovingPartExploiter = 54
    Hyperswapper = 55
    GravimetricCondensor = 56
    Accutron = 57
    RemoteRepairFacility = 58
    SacrificialOrb = 59
    LaneMagnetron = 60
    Disintegrator = 61
    LaneEndoscope = 62
    ToroidalBlaster = 63
    Gizmogrifier = 64
    Replenisher = 65
    SpecialtyBlaster = 66
    GyroInductor = 67
    PlasmaCoupler = 68
    Invulnerablizer = 69
    PhaseBomb = 70
    Colonizer = 71
    SelfDestructotron = 72
    InvasionModule = 73
    MassCondensor = 74
    Hyperfuel = 75
    None_ = 255

"""
public struct Gizmo
    {
        public GizmoType Index;
        public byte Depleted; // charges remaining
        public byte Unknown_2;
        public byte Unknown_3;
        public byte Unknown_4;
        public byte Unknown_5;
        public byte Unknown_6;
    }
"""

@dataclass
class Gizmo:
    Index: GizmoType
    Depleted: int
    Unknown_2: int
    Unknown_3: int
    Unknown_4: int
    Unknown_5: int
    Unknown_6: int

"""
public class Ship
    {
        public short Unknown_0;
        public int ShipId;
        public int AttackStrength; // ship display screen, 1 = 0.25 blocks
        public int ShieldStrength; // ship display screen, 1 = 0.25 blocks
        public int StarlaneTravelMultiplierBlue; // i.e. 1 = default time, 2 = twice as quick, 3 = three times as quick. Game adds Blue and Red to determine the multiplier
        public int StarlaneTravelMultiplierRed; // i.e. 1 = default time, 2 = twice as quick, 3 = three times as quick. Game adds Blue and Red to determine the multiplier
        public int EngineStrength; // ship display screen, 1 = 0.25 blocks
        public int Unknown_26;
        public int PowerStrength; // ship display screen, 1 = 0.25 blocks
        public int Unknown_34;
        public int ScannerStrength; // ship display screen, 1 = 0.25 blocks
        public int Unknown_42;
        public int Unknown_46;
        public int Unknown_50;
        public int Unknown_54;
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 30)]
        public char[] Name;
        public int Unknown_88; // Day ship construction commenced ?
        public short OwnerRaceIndex;
        public byte U01;
        public byte U02;
        public byte U03;
        public byte U04;
        public byte U05;
        public byte Order; // 0 - under construction, 1 - move to starlane, 7 - move to position (in system)
        public byte U07;
        public byte U08;
        public byte U09;
        public byte U10;
        public byte U11;
        public byte U12;
        public byte U13;
        public byte U14;
        public byte U15;
        public byte U16;
        public byte U17;
        public byte U18;
        public byte U19;
        public byte U20;
        public float DestinationX;
        public float DestinationY;
        public float DestinationZ;
        public byte U33;
        public byte U34;
        public byte U35;
        public byte U36;
        public byte U37;
        public byte U38;
        public byte U39;
        public byte U40;
        public byte U41;
        public byte U42;
        public byte U43;
        public byte U44;
        public byte U45;
        public byte U46;
        public byte U47;
        public byte U48;
        public int Power;
        public int Integrity;
        public int Unknown1;
        public int Moves;
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 7)]
        public byte[] Unknown10;
        public float XAxis;
        public float YAxis;
        public float ZAxis;
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 25)]
        public Gizmo[] Gizmos;
        public int SlotCount;
        public short SlotCountUsed;
    }
"""

@dataclass
class Ship:
    Unknown_0: int
    ShipId: int
    AttackStrength: int
    ShieldStrength: int
    StarlaneTravelMultiplierBlue: int
    StarlaneTravelMultiplierRed: int
    EngineStrength: int
    Unknown_26: int
    PowerStrength: int
    Unknown_34: int
    Unknown_42: int
    Unknown_46: int
    Unknown_50: int
    Unknown_54: int
    Name: list[str]
    Unknown_88: int
    OwnerRaceIndex: int
    U01: int
    U02: int
    U03: int
    U04: int
    U05: int
    Order: int
    U07: int
    U08: int
    U09: int
    U10: int
    U11: int
    U12: int
    U13: int
    U14: int
    U15: int
    U16: int
    U17: int
    U18: int
    U19: int
    U20: int
    DestinationX: float
    DestinationY: float
    DestinationZ: float
    U33: int
    U34: int
    U35: int
    U36: int
    U37: int
    U38: int
    U39: int
    U40: int
    U41: int
    U42: int
    U43: int
    U44: int
    U45: int
    U46: int
    U47: int
    U48: int
    Power: int
    Integrity: int
    Unknown1: int
    Moves: int
    Unknown10: list[int]
    XAxis: float
    YAxis: float
    ZAxis: float
    Gizmos: list[Gizmo]
    SlotCount: int
    SlotCountUsed: int

"""
public enum RelationshipState : byte
    {
        Unknown = 0,
        Peace = 1,
        War = 2,
        Alliance = 3 //?
    }
"""

class RelationshipState(Enum):
    Unknown = 0
    Peace = 1
    War = 2
    Alliance = 3

"""
public class Diplomacy
    {
        public short Unknown_0; // always 0x0000
        public byte RaceIndex;
        public byte Portait;
        public byte Colour;
        public short Extinct; // 0 = no, -1 = yes
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 409)]
        public byte[] Unknown_7;
        public int SpecialAbilityDiscount; // Subtract this from the special ability usage rate to get the current days until the ability can be used
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 14)]
        public byte[] Unknown_418;
        public short ShipPatience;
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 7)]
        public short[] RelationshipToPlayer1Trackers; // numeric representation of relationship, starts at start_attitude
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 7)]
        public RelationshipState[] RelationshipToPlayerStates;
        public short NEG_PLAYER_TURNS;
        public short DECLARE_WAR;
        public short ACCEPT_PEACE;
        public short PROPOSE_PEACE;
        public short BREAK_ALLIANCE;
        public short ACCEPT_ALLIANCE;
        public short PROPOSE_ALLIANCE;
        public short START_ATTITUDE;
        public short BIO_PERIOD;
        public short BIO_MAXPOSITVE;
        public short BIO_MAXNEGATIVE;
        [MarshalAs(UnmanagedType.ByValArray, ArraySubType = UnmanagedType.U1, SizeConst = 15)]
        public byte[] Unknown_480;       
    }
"""

@dataclass
class Diplomacy:
    Unknown_0: int
    RaceIndex: int
    Portait: int
    Colour: int
    Extinct: int
    Unknown_7: list[int]
    SpecialAbilityDiscount: int
    Unknown_418: list[int]
    ShipPatience: int
    RelationshipToPlayer1Trackers: list[int]
    RelationshipToPlayerStates: list[RelationshipState]
    NEG_PLAYER_TURNS: int
    DECLARE_WAR: int
    ACCEPT_PEACE: int
    PROPOSE_PEACE: int
    BREAK_ALLIANCE: int
    ACCEPT_ALLIANCE: int
    PROPOSE_ALLIANCE: int
    START_ATTITUDE: int
    BIO_PERIOD: int
    BIO_MAXPOSITVE: int
    BIO_MAXNEGATIVE: int
    Unknown_480: list[int]

"""
public enum StarlaneType : int
    {
        Blue = 0,
        Red,
        BlueBlocked,
        RedBlocked
    }
"""

class StarlaneType(Enum):
    Blue = 0
    Red = 1
    BlueBlocked = 2
    RedBlocked = 3

"""
public class StarLane
    {
        public int SourceSystem;
        public int DestinationSystem;
        public int Source_X;
        public int Source_Y;
        public int Source_Z;
        public int Destination_X;
        public int Destination_Y;
        public int Destination_Z;
        public byte KnownBy; // Bitmask of which players know of this starlane
        public short ControlledByPlayer; // 0 - no, 1 - yes
        public StarlaneType StarlaneType;
    }
"""

@dataclass
class StarLane:
    SourceSystem: int
    DestinationSystem: int
    Source_X: int
    Source_Y: int
    Source_Z: int
    Destination_X: int
    Destination_Y: int
    Destination_Z: int
    KnownBy: int
    ControlledByPlayer: int
    StarlaneType: StarlaneType

"""
public class StarLaneCount
    {
        public byte U1;
        public byte U2;
        public byte U3;
        public byte U4;
        public byte U5;
        public byte U6;
        public byte U7;
        public byte U8;
        public byte U9;
        public byte U10;
        public byte U11;
        public byte U12;
        public byte U13;
        public byte U14;
        public byte U15;
        public byte U16;
        public byte U17;
        public byte U18;
        public byte U19;
        public byte U20;
        public byte U21;
        public byte U22;
        public byte U23;
        public byte U24;
        public byte U25;
        public byte U26;
        public byte U27;
        public byte U28;
        public byte U29;
        public byte U30;
        public byte U31;
        public byte U32;
        public byte U33;
        public byte U34;
        public byte U35;
        public byte U36;
        public byte U37;
        public byte U38;
        public byte U39;
        public byte U40;
        public byte U41;
        public byte U42;
        public byte U43;
        public byte U44;
        public byte U45;
        public byte U46;
        public byte U47;
        public byte U48;
        public byte U49;
        public byte U50;
        public byte U51;
        public byte U52;
        public byte U53;
        public byte U54;
        public byte U55;
        public byte U56;
        public byte U57;
        public byte U58;
        public byte U59;
        public byte U60;
        public byte U61;
        public byte U62;
        public byte U63;
        public byte U64;
        public byte U65;
        public byte U66;
        public byte U67;
        public byte U68;
        public byte U69;
        public byte U70;
        public byte U71;
        public byte U72;
        public byte U73;
        public byte U74;
        public byte U75;
        public byte U76;
        public byte U77;
        public byte U78;
        public byte U79;
        public byte U80;
        public byte U81;
        public byte U82;
        public byte U83;
        public byte U84;
        public byte U85;
        public byte U86;
        public byte U87;
        public byte U88;
        public byte U89;
        public byte U90;
        public byte U91;
        public byte U92;
        public byte U93;
        public byte U94;
        public byte U95;
        public byte U96;
        public byte U97;
        public byte U98;
        public byte U99;
        public byte U100;
    }
"""

@dataclass
class StarLaneCount:
    U1: int
    U2: int
    U3: int
    U4: int
    U5: int
    U6: int
    U7: int
    U8: int
    U9: int
    U10: int
    U11: int
    U12: int
    U13: int
    U14: int
    U15: int
    U16: int
    U17: int
    U18: int
    U19: int
    U20: int
    U21: int
    U22: int
    U23: int
    U24: int
    U25: int
    U26: int
    U27: int
    U28: int
    U29: int
    U30: int
    U31: int
    U32: int
    U33: int
    U34: int
    U35: int
    U36: int
    U37: int
    U38: int
    U39: int
    U40: int
    U41: int
    U42: int
    U43: int
    U44: int
    U45: int
    U46: int
    U47: int
    U48: int
    U49: int
    U50: int
    U51: int
    U52: int
    U53: int
    U54: int
    U55: int
    U56: int
    U57: int
    U58: int
    U59: int
    U60: int
    U61: int
    U62: int
    U63: int
    U64: int
    U65: int
    U66: int
    U67: int
    U68: int
    U69: int
    U70: int
    U71: int
    U72: int
    U73: int
    U74: int
    U75: int
    U76: int
    U77: int
    U78: int
    U79: int
    U80: int
    U81: int
    U82: int
    U83: int
    U84: int
    U85: int
    U86: int
    U87: int
    U88: int
    U89: int
    U90: int
    U91: int
    U92: int
    U93: int
    U94: int
    U95: int
    U96: int
    U97: int
    U98: int
    U99: int
    U100: int

"""
public class SavFile
    {
        public Header Header;
        public List<ResearchItem> ResearchItems = new List<ResearchItem>();
        public List<short> CurrentResearchItems = new List<short>();
        public byte[] Unknown1 = new byte[10];
        public int Unknown2; // always 0
        public ManagementType ResearchManagementType;
        public int Unknown3; // always -1
        public List<StarSystem> StarSystems = new List<StarSystem>();
        public List<PlanetStructure> PlanetStructures = new List<PlanetStructure>();
        public List<Planet> Planets = new List<Planet>();
        public short Unknown4;
        public List<Ship> Ships = new List<Ship>();
        public short Unknown5;
        public List<Diplomacy> Diplomacies = new List<Diplomacy>();
        public short Unknown6;
        public List<StarLane> StarLanes = new List<StarLane>();
        public List<StarLaneCount> StarLaneCounts = new List<StarLaneCount>();
        public byte[] Unknown7 = new byte[7672];
    }
"""

@dataclass
class SavFile:
    Header: Header
    ResearchItems: list[ResearchItem]
    CurrentResearchItems: list[int]
    Unknown1: list[int]
    Unknown2: int
    ResearchManagementType: ManagementType
    Unknown3: int
    StarSystems: list[StarSystem]
    PlanetStructures: list[PlanetStructure]
    Planets: list[Planet]
    Unknown4: int
    Ships: list[Ship]
    Unknown5: int
    Diplomacies: list[Diplomacy]
    Unknown6: int
    StarLanes: list[StarLane]
    StarLaneCounts: list[StarLaneCount]
    Unknown7: list[int]

