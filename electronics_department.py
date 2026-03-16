"""
Electronics Department - Student Identification System
"""

class ElectronicsStudent:
    def __init__(self):
        self.students = []
    
    def add_student(self, roll_no, name, year, specialization):
        """Add a new student to the department"""
        student = {
            'roll_no': roll_no,
            'name': name,
            'year': year,
            'specialization': specialization,
            'id_card': f"EC{year}{roll_no[-4:]}"
        }
        self.students.append(student)
        print(f"✅ Student {name} added successfully!")
        return student
    
    def find_student(self, search_term):
        """Find student by name, roll number, or ID card"""
        for student in self.students:
            if (search_term.lower() in student['name'].lower() or 
                search_term == student['roll_no'] or 
                search_term == student['id_card']):
                return student
        return None
    
    def display_all(self):
        """Display all students in the department"""
        if not self.students:
            print("📝 No students in the department yet.")
            return
        
        print("\n" + "="*60)
        print("ELECTRONICS DEPARTMENT - STUDENT LIST")
        print("="*60)
        for s in self.students:
            print(f"ID: {s['id_card']} | Roll: {s['roll_no']} | {s['name']} | Year {s['year']} | {s['specialization']}")
        print("="*60)
    
    def year_summary(self, year):
        """Get summary of students in a particular year"""
        year_students = [s for s in self.students if s['year'] == year]
        specializations = {}
        
        for s in year_students:
            spec = s['specialization']
            specializations[spec] = specializations.get(spec, 0) + 1
        
        return {
            'total': len(year_students),
            'specializations': specializations
        }

# Quick demo
if __name__ == "__main__":
    dept = ElectronicsStudent()
    
    # Add some sample students
    dept.add_student("EC2023001", "Arjun Kumar", 2, "VLSI Design")
    dept.add_student("EC2023050", "Priya Singh", 2, "Embedded Systems")
    dept.add_student("EC2022004", "Rahul Verma", 3, "Communication")
    dept.add_student("EC2023105", "Ananya Patel", 1, "IoT")
    dept.add_student("EC2022088", "Vikram Shah", 3, "VLSI Design")
    
    # Display all students
    dept.display_all()
    
    # Search for a student
    print("\n🔍 Searching for 'Priya':")
    student = dept.find_student("Priya")
    if student:
        print(f"Found: {student['name']} (ID: {student['id_card']})")
    
    # Year summary
    print("\n📊 Year 3 Summary:")
    summary = dept.year_summary(3)
    print(f"Total Students: {summary['total']}")
    print(f"Specializations: {summary['specializations']}")
