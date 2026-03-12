class Student:
    def __init__(self, id, name, mat, eng, chi, phy, che):
        self.id = id
        self.name = name
        self.math = mat
        self.english = eng
        self.chinese = chi
        self.physic = phy
        self.chemistry = che


STUDENTS = (
    Student(20240622, "Kendrick",   92, 100, 60, 72, 74),
    Student(20240623, "Marshall",   90, 100, 42, 51, 49),
    Student(20240624, "Wayne",      70, 100, 40, 50, 32),
    Student(20240625, "Feuerstein", 85, 100, 54, 82, 72),
    Student(20240626, "Jermaine",   95, 100, 47, 90, 91)
)