import unittest
from datetime import date
from sql_connector import *

class TestGetFunctions(unittest.TestCase):
    def test_get_caller(self):
        # Expected output for the test
        expected_output = (
            1, 'Alice Johnson', 'Jane Doe', 'jane.doe@example.com', 
            date(2024, 1, 15), '555-1234', 'Referral', 
            'Follow-up on interest.', 1, None, date(2024, 1, 20)
        )

        # Call the function with test input
        result = get_caller(
            staff_name='Alice Johnson',
            caller_name='Jane Doe',
            caller_email='jane.doe@example.com',
            call_date=date(2024, 1, 15),
            phone='555-1234',
            referral_type='Referral',
            tour_scheduled=1,
            follow_up_date=date(2024, 1, 20)
        )[0]

        # Assert that the result matches the expected output
        self.assertEqual(result, expected_output)

    def test_get_tour(self):
        expected_output = (1, date(2024, 2, 1), 1, None, 'Dr. Adams', 'Jane Doe', 'Discussed options.', 1, date(2024, 3, 1), 0, 1, 'Very interested in joining.', 0, None)

        result = get_tour(tour_date=date(2024,2,1), attended=1, clinicians='Dr. Adams', 
             strategies_used=1, aep_deadline=date(2024,3,1), 
             joined_after=0, likely_to_join=1, 
             canceled=0)[0]
        
        self.assertEqual(result, expected_output)

    def test_get_member(self):
        expected_output = (
            1, 'Alice Johnson', 30, date(1993,5,10), 'alice.johnson@example.com', 
            date(2024,1,1), date(2023,12,15), 2, '555-1234', '123 Main St', 
            'Sample County', 'F', True, True, False, 'Alder Program A',
            '{"Aphasia History": {"Aphasia Onset": "2022-06-01", "Cause of Aphasia": "Stroke", "Currently in therapy": "Yes"}}'
        )

        result = get_member(
            name='Alice Johnson',
            age=30,
            dob='1993-05-10',
            email='alice.johnson@example.com',
            aep_completion_date='2024-01-01',
            join_date='2023-12-15',
            schedule=2,
            phone='555-1234',
            address='123 Main St',
            county='Sample County',
            gender='F',
            veteran=True,
            joined=True,
            caregiver_needed=False,
            alder_program='Alder Program A'
        )[0]

        self.assertEqual(result, expected_output)

    def test_get_medical_history_form(self):
        expected_output = (1, 'Dr. Sarah Connor', 'Neurologist', '789 Pine St', '555-9999', 'Stroke', date(2021, 6, 1), 'L', 'Frontal Lobe', 'Aphasia', 'Hypertension', 1, date(2023, 12, 15), 0, 'None', 'Lisinopril', 0, 'None', 'No impairments', 'Regular', 0, 'None', 0, None, date(2024, 1, 20), '{"Diabetes": "No", "Brain Surgery": "No", "Heart Disease": "No", "Memory Impairment": "No", "Clinical Depression": "Yes"}')

        result = get_medical_history_form(physician_name='Dr. Sarah Connor', specialty='Neurologist', 
                              physician_address='789 Pine St', physician_phone='555-9999', 
                              aphasia_cause='Stroke', aphasia_onset=date(2021,6,1), 
                              stroke_location='L', lesion_location='Frontal Lobe', 
                              primary_diagnosis='Aphasia', secondary_diagnosis='Hypertension', 
                              seizure_history=True, last_seizure_date=date(2023,12,15), 
                              anti_seizure_med=False, hearing_aid=False, 
                              swallowing_strategies=False, 
                              other_visual_impairments=False,
                              completion_date=date(2024,1,20))[0]

        self.assertEqual(result, expected_output)

    def test_get_incident_report(self):
        expected_output = (1, date(2024, 1, 10), 'Community Center', 'Alice Johnson', 'Slip and fall incident.', 'First aid provided and monitored for any further issues.')
        
        result = get_incident_report(
            incident_date= date(2024,1,10), incident_location= 'Community Center'
        )[0]

        self.assertEqual(result, expected_output)

    def test_get_evaluation(self):
        expected_output = (1, 1, 'Dr. Emily Davis', 'Standard Aphasia Test', date(2024, 1, 15))

        result = get_evaluation(
            completed=True, administerer= 'Dr. Emily Davis',
            date_administered=date(2024,1,15)
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_transportation_information(self):
        expected_output = (1, 1, 'City Bus Co.', '555-0000', 1, 'Alice Johnson', 'Sister', '555-1234', '555-5678')

        result = get_transportation_information(
            bus_transport= True, bus_company= 'City Bus Co.',
            bus_contact_phone='555-0000', picked_up=True,
            pickup_person='Alice Johnson', relationship_to_member='Sister',
            primary_phone='555-1234', secondary_phone='555-5678'
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_caregiver(self):
        expected_output = (1, 'Alice Johnson', '555-1234', 'alice.johnson@example.com', 'Sister', date(2024, 1, 15), 'Interested in support groups.', 'Group A', 1)

        result = get_caregiver(
            name='Alice', phone='555-1234', email='alice.johnson@example.com',
            date_contacted=date(2024,1,15), group_attending='Group A', attending=True
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_attending_caregiver(self):
        expected_output = (1, 'Professional Caregiver', 'F', 'Asian', 'Nurse', 1, date(2024, 1, 10), 'None', 'None', 1, date(2024, 1, 1), date(2024, 12, 31), 'Very attentive.', 'Active participant in group activities.', 1)

        result = get_attending_caregiver(
            caregiver_type='Professional Caregiver', sex='F', race='Asian',
            occupations='Nurse', support_group=True,
            covid_vaccine_date=date(2024,1,10), allergies='None',
            media_release=True,start_date=date(2024,1,1),end_date=date(2024,12,31),
            robly=True
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_emergencry_contact(self):
        expected_output = (1, 'John Doe', 'Father', '555-1111', '555-2222', '555-3333', 'john.doe@example.com', '123 Main St, Anytown, USA', date(2024, 1, 10))

        result = get_emergency_contact(
            name='John Doe', relationship='Father', day_phone='555-1111',
            evening_phone='555-2222', cell_phone='555-3333', 
            address='123 Main St, Anytown, USA', completion_date=date(2024,1,10)
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_volunteer(self):
        expected_output = (1, 'Emily Davis', '555-7777', '789 Maple St, Anytown, USA', 'emily.davis@example.com', 'Online', date(2024, 1, 5), date(2024, 1, 6), 'N/A', 1, 1, 3)

        result = get_volunteer(
            name='Emily', phone='555-7777', address='789 Maple St, Anytown, USA', email='emily.davis@example.com', 
            background_check_date=date(2024,1,5), video_watched_date=date(2024,1,6), 
            media_release=True, confidentiality=True, 
            training_level=3
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_applications(self):
        expected_output = (1, date(1985, 3, 15), 'Speech Therapist', 1, '5 years at local clinic', "Master's Degree in Speech-Language Pathology", 'Reading, Traveling', 'English, Spanish', 1, 0, date(2024, 1, 10))

        result = get_applications(
            birthday=date(1985,3,15), occupation='Speech Therapist', is_slp=True, 
            languages_spoken='Spanish', will_substitute=True, 
            convicted_of_crime=False, application_date=date(2024,1,10)
        )[0]

        self.assertEqual(result,expected_output)

    def test_get_outreach(self):
        expected_output = (1, date(2024, 1, 13), 'Sarah Connor', 'Health Services Organization', 'Non-Profit', 'Informational Session', 'Community Center', 25, 1, 'Successful outreach with positive feedback.')

        result = get_outreach(
            contacted_date=date(2024,1,13), staff_contacted='Sarah Connor', 
            organization='Health Services', org_type='Non-Profit', outreach_type='Informational Session', 
            target_location='Community Center', num_people=25, robly=True
        )[0]

        self.assertEqual(result,expected_output)


if __name__ == '__main__':
    unittest.main()
