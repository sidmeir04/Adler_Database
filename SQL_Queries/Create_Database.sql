SET foreign_key_checks = 0;
DROP DATABASE adler_aphasia_center;
CREATE DATABASE adler_aphasia_center;
SET foreign_key_checks = 1;

USE adler_aphasia_center;
CREATE TABLE Caller (
    id INT AUTO_INCREMENT PRIMARY KEY,
    staff_who_took_the_call VARCHAR(50) NOT NULL,
    name_of_caller VARCHAR(50),
    caller_email VARCHAR(50),
    date_of_call DATE,
    phone_number VARCHAR(20),
    type_of_referral VARCHAR(50),
    additional_notes TEXT,
    tour_scheduled BOOLEAN,
    why_was_tour_not_scheduled TEXT,
    follow_up_date DATE
);

CREATE TABLE Tour (
    id INT AUTO_INCREMENT PRIMARY KEY,
    tour_date DATE,                  -- Date of the tour
    attended BOOLEAN,                -- Whether the person attended the tour
    no_join_reason TEXT,             -- Reason for not joining
    clinicians VARCHAR(50),          -- Clinicians who toured
    attendees TEXT,                  -- Who attended the tour
    interactions TEXT,               -- Interactions during the tour
    strategies_used BOOLEAN,         -- Whether strategies were used
    aep_deadline DATE,               -- Deadline to join AEP
    joined_after BOOLEAN,            -- Whether they joined after the tour
    likely_to_join BOOLEAN,          -- Likely to join after the tour
    notes TEXT,                      -- Additional notes
    canceled BOOLEAN,                -- Whether the tour was canceled
    cancel_reason TEXT               -- Reason for cancelation
);

CREATE TABLE Member (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    age INT,
    dob DATE,                          -- Date of birth
    email VARCHAR(50),
    aep_completion_date DATE,          -- Date completed AEP
    join_date DATE,                    -- Date joined
    schedule INT,                      -- Schedule in weeks or other interval
    phone VARCHAR(20),
    address VARCHAR(50),
    county VARCHAR(50),
    gender CHAR(1),                    -- 'M' or 'F'
    veteran BOOLEAN,                   -- Veteran status
    joined BOOLEAN,                    -- Whether the member joined
    caregiver_needed BOOLEAN,          -- Whether a caregiver is needed
    alder_program VARCHAR(50),         -- Alder program info
    member_info JSON                   -- Detailed member information
);

CREATE TABLE Membership_Enrollment_Form (
    id INT AUTO_INCREMENT PRIMARY KEY,
    sexual_orientation VARCHAR(20),
    race VARCHAR(50),
    income INT,
    living_status INT,                   -- Living status code
    grew_up VARCHAR(50),
    occupations TEXT,                    -- List of occupations
    prev_speech_therapy TEXT,            -- Previous speech therapy
    other_therapy TEXT,
    hearing_loss BOOLEAN,
    hearing_aid BOOLEAN,
    aphasia_cause VARCHAR(50),
    aphasia_onset VARCHAR(50),           -- Date of onset of aphasia
    brain_location VARCHAR(50),          -- Location in the brain affected
    allergies TEXT,
    medications TEXT,
    filled_by VARCHAR(50),               -- Filled out by
    completed_date DATE,                 -- Date completed
    patient_info JSON                    -- Detailed patient information
);

CREATE TABLE Medical_History_Form (
    id INT AUTO_INCREMENT PRIMARY KEY,
    physician_name VARCHAR(50),            -- Physician completing the form
    specialty VARCHAR(50),                 -- Medical specialty
    physician_address VARCHAR(50),
    physician_phone VARCHAR(20),
    aphasia_cause VARCHAR(50),
    aphasia_onset DATE,                    -- Date of onset of aphasia
    stroke_location CHAR(1),               -- 'r' for right, 'l' for left
    lesion_location VARCHAR(50),
    primary_diagnosis VARCHAR(50),         -- Primary medical diagnosis
    secondary_diagnosis VARCHAR(50),       -- Secondary medical diagnosis
    seizure_history BOOLEAN,               -- History of seizures
    last_seizure_date DATE,                -- Date of last seizure
    anti_seizure_med BOOLEAN,              -- On anti-seizure medication
    allergies TEXT,
    medications TEXT,
    hearing_aid BOOLEAN,
    hearing_impairment TEXT,               -- Hearing impairments
    swallowing_impairments TEXT,           -- Swallowing impairments
    current_diet TEXT,                     -- Current diet
    swallowing_strategies BOOLEAN,         -- Compensatory strategies
    visual_impairments TEXT,               -- Visual impairments
    visual_field_cut BOOLEAN,              -- Visual field cut present
    other_visual_impairments VARCHAR(50),  -- Additional visual impairments
    completion_date DATE,                  -- Date of completion
    other_conditions JSON                  -- Other medical conditions
);

CREATE TABLE Incident_Report (
    id INT AUTO_INCREMENT PRIMARY KEY,
    incident_date DATE,               -- Date of the incident
    incident_location VARCHAR(50),    -- Location of the incident
    persons_involved TEXT,            -- Persons involved in the incident
    description TEXT,                 -- Brief description of the incident
    action_taken TEXT                 -- Action taken following the incident
);

CREATE TABLE Evaluation (
    id INT AUTO_INCREMENT PRIMARY KEY,
    completed BOOLEAN,                -- Whether the evaluation was completed
    administerer VARCHAR(50),         -- Who administered the evaluation
    test_type TEXT,                   -- Type of test administered
    date_administered DATE            -- Date the evaluation was administered
);

CREATE TABLE Transportation_Information (
    id INT AUTO_INCREMENT PRIMARY KEY,
    bus_transport BOOLEAN,                -- Whether bus transport is used
    bus_company VARCHAR(50),              -- Bus transport company name
    bus_contact_phone VARCHAR(20),        -- Phone number for the bus company
    picked_up BOOLEAN,
    pickup_person VARCHAR(50),            -- Person picking up the member
    relationship_to_member VARCHAR(50),
    primary_phone VARCHAR(20),            -- Primary contact phone number
    secondary_phone VARCHAR(20)           -- Secondary contact phone number
);

CREATE TABLE Caregiver (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),                -- Caregiver's name
    phone VARCHAR(20),               -- Phone number
    email VARCHAR(50),               -- Caregiver's email
    relationship VARCHAR(50),        -- Relationship to person with aphasia -
    date_contacted DATE,             -- Date contacted
    notes TEXT,                      -- Additional notes
    group_attending VARCHAR(50),     -- Group attending
    attending BOOLEAN                -- Whether attending or not
);

CREATE TABLE Attending_Caregiver (
    id INT AUTO_INCREMENT PRIMARY KEY,
    caregiver_type VARCHAR(50),      -- Type of caregiver
    sex CHAR(1),                     -- Sex of caregiver ('M' or 'F')
    race VARCHAR(50),                -- Race of caregiver
    occupations VARCHAR(150),        -- Caregiver's occupations
    support_group BOOLEAN,           -- Whether attending a support group
    covid_vaccine_date DATE,         -- Date of COVID vaccine
    allergies VARCHAR(100),          -- Allergies
    medications TEXT,                -- Medications
    media_release BOOLEAN,           -- Media release consent
    start_date DATE,                 -- Start date of caregiving
    end_date DATE,                   -- End date of caregiving
    general_notes TEXT,              -- General notes about the caregiver
    participation TEXT,              -- Participation details
    robly BOOLEAN                    -- If Robly is used for communication
);

CREATE TABLE Emergency_Contact (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),               -- Emergency contact's name
    relationship VARCHAR(50),        -- Relationship to the member
    day_phone VARCHAR(20),           -- Daytime phone number
    evening_phone VARCHAR(20),       -- Evening phone number
    cell_phone VARCHAR(20),          -- Cell phone number
    email VARCHAR(50),               -- Email address
    address VARCHAR(100),            -- Contact's address
    completion_date DATE             -- Date the form was completed
);

CREATE TABLE Volunteer (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),                 -- Volunteer name
    phone VARCHAR(20),                -- Phone number
    address VARCHAR(50),              -- Volunteer address
    email VARCHAR(50),                -- Volunteer email
    referral_source TEXT,             -- Source of referral
    background_check_date DATE,       -- Date background check was completed
    video_watched_date DATE,          -- Date watched the orientation video
    emergency_contacts TEXT,          -- Emergency contacts
    media_release BOOLEAN,            -- Media release consent
    confidentiality BOOLEAN,           -- Confidentiality agreement
    training_level INT                 -- Training level (0-4)
);

CREATE TABLE Outreach (
    id INT AUTO_INCREMENT PRIMARY KEY,
    contacted_date DATE,              -- Date contacted
    staff_contacted VARCHAR(50),      -- Staff member contacted
    organization VARCHAR(50),         -- Name of the organization
    org_type VARCHAR(50),             -- Type of organization
    outreach_type VARCHAR(50),        -- Type of outreach conducted
    target_location VARCHAR(50),      -- Target location for outreach
    num_people INT,                   -- Number of people contacted
    robly BOOLEAN,                    -- If Robly was used for communication
    notes TEXT                        -- Additional notes regarding outreach
);