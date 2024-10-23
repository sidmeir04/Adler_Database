USE adler_aphasia_center;

INSERT INTO Caller (staff, caller_name, caller_email, call_date, phone_number, referral_type, additional_notes, tour_scheduled, tour_not_scheduled_reason, follow_up_date) VALUES
('Alice Johnson', 'Jane Doe', 'jane.doe@example.com', '2024-01-15', '555-1234', 'Referral', 'Follow-up on interest.', TRUE, NULL, '2024-01-20'),
('Bob Smith', 'John Smith', 'john.smith@example.com', '2024-01-16', '555-5678', 'Self', 'Needs more information.', FALSE, 'No response', '2024-01-25');

INSERT INTO Tour (tour_date, attended, no_join_reason, clinicians, attendees, interactions, strategies_used, aep_deadline, joined_after, likely_to_join, additional_notes, canceled, cancel_reason) VALUES
('2024-02-01', TRUE, NULL, 'Dr. Adams', 'Jane Doe', 'Discussed options.', TRUE, '2024-03-01', FALSE, TRUE, 'Very interested in joining.', FALSE, NULL),
('2024-02-05', FALSE, 'Scheduling conflict', 'Dr. Lee', 'John Smith', 'Requested follow-up.', FALSE, '2024-03-05', TRUE, FALSE, 'Needs more info.', TRUE, 'Personal issues.');

INSERT INTO Member (name, age, dob, email, aep_completion_date, join_date, schedule, phone, address, county, gender, veteran, joined, caregiver_needed, alder_program, member_info) VALUES
('Alice Johnson', 30, '1993-05-10', 'alice.johnson@example.com', '2024-01-01', '2023-12-15', 2, '555-1234', '123 Main St', 'Sample County', 'F', TRUE, TRUE, FALSE, 'Alder Program A', '{"Aphasia History": {"Aphasia Onset": "2022-06-01", "Cause of Aphasia": "Stroke", "Currently in therapy": "Yes"}}'),
('Bob Smith', 45, '1978-03-20', 'bob.smith@example.com', '2024-02-01', '2024-01-10', 1, '555-5678', '456 Elm St', 'Sample County', 'M', FALSE, FALSE, TRUE, 'Alder Program B', '{"Aphasia History": {"Aphasia Onset": "2021-08-15", "Cause of Aphasia": "Trauma", "Currently in therapy": "No"}}');

-- INSERT INTO Membership_Enrollment_Form (sexual_orientation, race, income, living_status, grew_up, occupations, prev_speech_therapy, other_therapy, hearing_loss, hearing_aid, aphasia_cause, aphasia_onset, brain_location, allergies, medications, filled_by, completed_date, patient_info) VALUES
-- ('Straight', 'Caucasian', 50000, 1, 'City', 'Teacher', 'No', 'Physical Therapy', FALSE, TRUE, 'Stroke', '2021-06-01', 'Left Hemisphere', 'None', 'None', 'Alice Johnson', '2024-01-20', '{"Education": {"Highest Level of Education": 4, "Special Education": TRUE, "Special Education Type": "None", "Spelling Ability": 4, "Reading Ability": 4, "Spelling Ability Post-Stroke": 3, "Reading Ability Post-Stroke": 3, "Handedness": "R", "Handedness Post-Stroke": "R"}}');

INSERT INTO Medical_History_Form (physician_name, specialty, physician_address, physician_phone, aphasia_cause, aphasia_onset, stroke_location, lesion_location, primary_diagnosis, secondary_diagnosis, seizure_history, last_seizure_date, anti_seizure_med, allergies, medications, hearing_aid, hearing_impairment, swallowing_impairments, current_diet, swallowing_strategies, visual_impairments, visual_field_cut, completion_date, other_conditions) VALUES
('Dr. Sarah Connor', 'Neurologist', '789 Pine St', '555-9999', 'Stroke', '2021-06-01', 'L', 'Frontal Lobe', 'Aphasia', 'Hypertension', TRUE, '2023-12-15', FALSE, 'None', 'Lisinopril', FALSE, 'None', 'No impairments', 'Regular', FALSE, 'None', FALSE, '2024-01-20', '{"Diabetes": "No", "Heart Disease": "No", "Brain Surgery": "No", "Memory Impairment": "No", "Clinical Depression": "Yes"}');

INSERT INTO Incident_Report (incident_date, incident_location, persons_involved, description, action_taken) VALUES
('2024-01-10', 'Community Center', 'Alice Johnson', 'Slip and fall incident.', 'First aid provided and monitored for any further issues.'),
('2024-01-12', 'Local Park', 'Bob Smith', 'Minor injury during exercise.', 'Administered ice and provided follow-up advice.');

INSERT INTO Evaluation (completed, administerer, test_type, date_administered) VALUES
(TRUE, 'Dr. Emily Davis', 'Standard Aphasia Test', '2024-01-15'),
(FALSE, 'Dr. John Smith', 'Cognitive Assessment', '2024-01-16');

INSERT INTO Transportation_Information (bus_transport, bus_company, bus_contact_phone, picked_up, pickup_person, relationship_to_member, primary_phone, secondary_phone) VALUES
(TRUE, 'City Bus Co.', '555-0000', TRUE, 'Alice Johnson', 'Sister', '555-1234', '555-5678'),
(FALSE, NULL, NULL, TRUE, 'John Smith', 'Friend', '555-5678', '555-8765');

INSERT INTO Caregiver (name, phone, email, relationship, date_contacted, notes, group_attending, attending) VALUES
('Alice Johnson', '555-1234', 'alice.johnson@example.com', 'Sister', '2024-01-15', 'Interested in support groups.', 'Group A', TRUE),
('Bob Smith', '555-5678', 'bob.smith@example.com', 'Friend', '2024-01-16', 'Looking for more information.', 'Group B', FALSE);

INSERT INTO Attending_Caregiver (caregiver_type, sex, race, occupations, support_group, covid_vaccine_date, allergies, medications, media_release, start_date, end_date, general_notes, participation, robly) VALUES
('Professional Caregiver', 'F', 'Asian', 'Nurse', TRUE, '2024-01-10', 'None', 'None', TRUE, '2024-01-01', '2024-12-31', 'Very attentive.', 'Active participant in group activities.', TRUE),
('Family Caregiver', 'M', 'Caucasian', 'Retired Teacher', FALSE, '2024-01-12', 'Peanuts', 'Aspirin', FALSE, '2024-01-02', '2024-12-30', 'Available most days.', 'Helps with daily activities.', FALSE);

INSERT INTO Emergency_Contact (name, relationship, day_phone, evening_phone, cell_phone, email, address, completion_date) VALUES
('John Doe', 'Father', '555-1111', '555-2222', '555-3333', 'john.doe@example.com', '123 Main St, Anytown, USA', '2024-01-10'),
('Jane Smith', 'Daughter', '555-4444', '555-5555', '555-6666', 'jane.smith@example.com', '456 Elm St, Anytown, USA', '2024-01-11');

INSERT INTO Volunteer (name, phone, address, email, referral_source, background_check_date, video_watched_date, emergency_contacts, media_release, confidentiality, training_level) VALUES
('Emily Davis', '555-7777', '789 Maple St, Anytown, USA', 'emily.davis@example.com', 'Online', '2024-01-05', '2024-01-06', 'N/A', TRUE, TRUE, 3),
('Michael Brown', '555-8888', '321 Oak St, Anytown, USA', 'michael.brown@example.com', 'Friend Referral', '2024-01-04', '2024-01-05', 'N/A', FALSE, TRUE, 2);

INSERT INTO Applications (birthday, occupation, is_slp, relevant_experience, education, interests_skills_hobbies, languages_spoken, will_substitute, convicted_of_crime, application_date) VALUES
('1985-03-15', 'Speech Therapist', TRUE, '5 years at local clinic', 'Master\'s Degree in Speech-Language Pathology', 'Reading, Traveling', 'English, Spanish', TRUE, FALSE, '2024-01-10'),
('1990-06-25', 'Teacher', FALSE, '3 years in special education', 'Bachelor\'s Degree in Education', 'Arts and Crafts, Music', 'English', FALSE, TRUE, '2024-01-12');

INSERT INTO Outreach (contacted_date, staff_contacted, organization, org_type, outreach_type, target_location, num_people, robly, notes) VALUES
('2024-01-13', 'Sarah Connor', 'Health Services Organization', 'Non-Profit', 'Informational Session', 'Community Center', 25, TRUE, 'Successful outreach with positive feedback.'),
('2024-01-14', 'John Smith', 'Local School', 'Educational', 'Workshops', 'Elementary School', 50, FALSE, 'Gave presentation on speech awareness.');