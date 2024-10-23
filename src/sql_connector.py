import mysql.connector
from mysql.connector import Error

def create_connection(host_name, user_name, user_password, db_name):
    connection = None
    try:
        connection = mysql.connector.connect(
            host=host_name,
            user=user_name,
            password=user_password,
            database=db_name
        )
        print("Connection to MySQL DB successful")
    except Error as e:
        print(f"The error '{e}' occurred")
    return connection

def fetch_members(connection):
    cursor = connection.cursor()
    try:
        cursor.execute("SELECT * FROM member")  # Adjust the query as needed
        rows = cursor.fetchall()  # Fetch all rows from the result set
        return rows
    except Error as e:
        print(f"The error '{e}' occurred")
        return None


def get_caller(staff_name='', caller_name='', caller_email = '', call_date=None, phone='', referral_type='', tour_scheduled=None, follow_up_date=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM caller WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments    
    if staff_name:
        query += " AND staff LIKE %s"
        filters.append(f'%{staff_name}%')
    
    if caller_name:
        query += " AND caller_name LIKE %s"
        filters.append(f'%{caller_name}%')
    
    if caller_email:
        query += " AND caller_email LIKE %s"
        filters.append(f'%{caller_email}%')

    if call_date:
        query += " AND call_date = %s"
        filters.append(call_date)
    
    if phone:
        query += " AND phone_number LIKE %s"
        filters.append(f'%{phone}%')
    
    if referral_type:
        query += " AND referral_type LIKE %s"
        filters.append(f'%{referral_type}%')
    
    if tour_scheduled is not None:
        query += " AND tour_scheduled = %s"
        filters.append(tour_scheduled)
    
    if follow_up_date:
        query += " AND follow_up_date = %s"
        filters.append(follow_up_date)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()

    return results

def get_tour(tour_date=None, attended=None, clinicians='', 
             strategies_used=None, aep_deadline=None, 
             joined_after=None, likely_to_join=None, 
             canceled=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM tour WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if tour_date is not None:
        query += " AND tour_date = %s"
        filters.append(tour_date)
    
    if attended is not None:
        query += " AND attended = %s"
        filters.append(attended)
    
    if clinicians:
        query += " AND clinicians LIKE %s"
        filters.append(f'%{clinicians}%')
    
    if strategies_used is not None:
        query += " AND strategies_used = %s"
        filters.append(strategies_used)
    
    if aep_deadline is not None:
        query += " AND aep_deadline = %s"
        filters.append(aep_deadline)
    
    if joined_after is not None:
        query += " AND joined_after = %s"
        filters.append(joined_after)
    
    if likely_to_join is not None:
        query += " AND likely_to_join = %s"
        filters.append(likely_to_join)
    
    if canceled is not None:
        query += " AND canceled = %s"
        filters.append(canceled)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    results = cursor.fetchall()
    
    return results

def get_member(name='', age=None, dob=None, email='', 
               aep_completion_date=None, join_date=None, 
               schedule=None, phone='', address='', 
               county='', gender='', veteran=None, 
               joined=None, caregiver_needed=None, alder_program=''):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM member WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if name:
        query += " AND name LIKE %s"
        filters.append(f'%{name}%')
    
    if age is not None:
        query += " AND age = %s"
        filters.append(age)
    
    if dob is not None:
        query += " AND dob = %s"
        filters.append(dob)
    
    if email:
        query += " AND email LIKE %s"
        filters.append(f'%{email}%')
    
    if aep_completion_date is not None:
        query += " AND aep_completion_date = %s"
        filters.append(aep_completion_date)
    
    if join_date is not None:
        query += " AND join_date = %s"
        filters.append(join_date)
    
    if schedule is not None:
        query += " AND schedule = %s"
        filters.append(schedule)
    
    if phone:
        query += " AND phone LIKE %s"
        filters.append(f'%{phone}%')
    
    if address:
        query += " AND address LIKE %s"
        filters.append(f'%{address}%')
    
    if county:
        query += " AND county LIKE %s"
        filters.append(f'%{county}%')
    
    if gender:
        query += " AND gender = %s"
        filters.append(gender)
    
    if veteran is not None:
        query += " AND veteran = %s"
        filters.append(veteran)
    
    if joined is not None:
        query += " AND joined = %s"
        filters.append(joined)
    
    if caregiver_needed is not None:
        query += " AND caregiver_needed = %s"
        filters.append(caregiver_needed)
    
    if alder_program:
        query += " AND alder_program LIKE %s"
        filters.append(f'%{alder_program}%')
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_membership_enrollment_form(sexual_orientation='', race='', income=None, 
                                    living_status=None, grew_up='', 
                                    hearing_loss=None, hearing_aid=None, 
                                    aphasia_cause='', aphasia_onset=None, 
                                    brain_location='', filled_by='', 
                                    completed_date=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Membership_Enrollment_Form WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if sexual_orientation:
        query += " AND sexual_orientation LIKE %s"
        filters.append(f'%{sexual_orientation}%')
    
    if race:
        query += " AND race LIKE %s"
        filters.append(f'%{race}%')
    
    if income is not None:
        query += " AND income = %s"
        filters.append(income)
    
    if living_status is not None:
        query += " AND living_status = %s"
        filters.append(living_status)
    
    if grew_up:
        query += " AND grew_up LIKE %s"
        filters.append(f'%{grew_up}%')
    
    if hearing_loss is not None:
        query += " AND hearing_loss = %s"
        filters.append(hearing_loss)
    
    if hearing_aid is not None:
        query += " AND hearing_aid = %s"
        filters.append(hearing_aid)
    
    if aphasia_cause:
        query += " AND aphasia_cause LIKE %s"
        filters.append(f'%{aphasia_cause}%')
    
    if aphasia_onset is not None:
        query += " AND aphasia_onset = %s"
        filters.append(aphasia_onset)
    
    if brain_location:
        query += " AND brain_location LIKE %s"
        filters.append(f'%{brain_location}%')
    
    if filled_by:
        query += " AND filled_by LIKE %s"
        filters.append(f'%{filled_by}%')
    
    if completed_date is not None:
        query += " AND completed_date = %s"
        filters.append(completed_date)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_medical_history_form(physician_name='', specialty='', 
                              physician_address='', physician_phone='', 
                              aphasia_cause='', aphasia_onset=None, 
                              stroke_location='', lesion_location='', 
                              primary_diagnosis='', secondary_diagnosis='', 
                              seizure_history=None, last_seizure_date=None, 
                              anti_seizure_med=None, hearing_aid=None, 
                              swallowing_strategies=None, 
                              other_visual_impairments='',
                              completion_date=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Medical_History_Form WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if physician_name:
        query += " AND physician_name LIKE %s"
        filters.append(f'%{physician_name}%')
    
    if specialty:
        query += " AND specialty LIKE %s"
        filters.append(f'%{specialty}%')
    
    if physician_address:
        query += " AND physician_address LIKE %s"
        filters.append(f'%{physician_address}%')
    
    if physician_phone:
        query += " AND physician_phone LIKE %s"
        filters.append(f'%{physician_phone}%')
    
    if aphasia_cause:
        query += " AND aphasia_cause LIKE %s"
        filters.append(f'%{aphasia_cause}%')
    
    if aphasia_onset is not None:
        query += " AND aphasia_onset = %s"
        filters.append(aphasia_onset)
    
    if stroke_location:
        query += " AND stroke_location = %s"
        filters.append(stroke_location)
    
    if lesion_location:
        query += " AND lesion_location LIKE %s"
        filters.append(f'%{lesion_location}%')
    
    if primary_diagnosis:
        query += " AND primary_diagnosis LIKE %s"
        filters.append(f'%{primary_diagnosis}%')
    
    if secondary_diagnosis:
        query += " AND secondary_diagnosis LIKE %s"
        filters.append(f'%{secondary_diagnosis}%')
    
    if seizure_history is not None:
        query += " AND seizure_history = %s"
        filters.append(seizure_history)
    
    if last_seizure_date is not None:
        query += " AND last_seizure_date = %s"
        filters.append(last_seizure_date)
    
    if anti_seizure_med is not None:
        query += " AND anti_seizure_med = %s"
        filters.append(anti_seizure_med)
    
    if hearing_aid is not None:
        query += " AND hearing_aid = %s"
        filters.append(hearing_aid)
    
    if swallowing_strategies is not None:
        query += " AND swallowing_strategies = %s"
        filters.append(swallowing_strategies)
    
    if other_visual_impairments:
        query += " AND other_visual_impairments LIKE %s"
        filters.append(f'%{other_visual_impairments}%')
    
    if completion_date is not None:
        query += " AND completion_date = %s"
        filters.append(completion_date)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_incident_report(incident_date=None, incident_location=''):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Incident_Report WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if incident_date is not None:
        query += " AND incident_date = %s"
        filters.append(incident_date)
    
    if incident_location:
        query += " AND incident_location LIKE %s"
        filters.append(f'%{incident_location}%')
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_evaluation(completed=None, administerer='', date_administered=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Evaluation WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if completed is not None:
        query += " AND completed = %s"
        filters.append(completed)
    
    if administerer:
        query += " AND administerer LIKE %s"
        filters.append(f'%{administerer}%')
    
    if date_administered is not None:
        query += " AND date_administered = %s"
        filters.append(date_administered)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_transportation_information(bus_transport=None, bus_company='', 
                                    bus_contact_phone='', picked_up=None, 
                                    pickup_person='', relationship_to_member='', 
                                    primary_phone='', secondary_phone=''):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Transportation_Information WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if bus_transport is not None:
        query += " AND bus_transport = %s"
        filters.append(bus_transport)
    
    if bus_company:
        query += " AND bus_company LIKE %s"
        filters.append(f'%{bus_company}%')
    
    if bus_contact_phone:
        query += " AND bus_contact_phone LIKE %s"
        filters.append(f'%{bus_contact_phone}%')
    
    if picked_up is not None:
        query += " AND picked_up = %s"
        filters.append(picked_up)
    
    if pickup_person:
        query += " AND pickup_person LIKE %s"
        filters.append(f'%{pickup_person}%')
    
    if relationship_to_member:
        query += " AND relationship_to_member LIKE %s"
        filters.append(f'%{relationship_to_member}%')
    
    if primary_phone:
        query += " AND primary_phone LIKE %s"
        filters.append(f'%{primary_phone}%')
    
    if secondary_phone:
        query += " AND secondary_phone LIKE %s"
        filters.append(f'%{secondary_phone}%')
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_caregiver(name='', phone='', email='', relationship='', 
                  date_contacted=None, group_attending='', 
                  attending=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Caregiver WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if name:
        query += " AND name LIKE %s"
        filters.append(f'%{name}%')
    
    if phone:
        query += " AND phone LIKE %s"
        filters.append(f'%{phone}%')
    
    if email:
        query += " AND email LIKE %s"
        filters.append(f'%{email}%')
    
    if relationship:
        query += " AND relationship LIKE %s"
        filters.append(f'%{relationship}%')
    
    if date_contacted is not None:
        query += " AND date_contacted = %s"
        filters.append(date_contacted)
    
    if group_attending:
        query += " AND group_attending LIKE %s"
        filters.append(f'%{group_attending}%')
    
    if attending is not None:
        query += " AND attending = %s"
        filters.append(attending)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_attending_caregiver(caregiver_type='', sex='', race='', 
                             occupations='', support_group=None, 
                             covid_vaccine_date=None, allergies='', 
                             media_release=None, start_date=None, 
                             end_date=None, robly=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Attending_Caregiver WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if caregiver_type:
        query += " AND caregiver_type LIKE %s"
        filters.append(f'%{caregiver_type}%')
    
    if sex:
        query += " AND sex = %s"
        filters.append(sex)
    
    if race:
        query += " AND race LIKE %s"
        filters.append(f'%{race}%')
    
    if occupations:
        query += " AND occupations LIKE %s"
        filters.append(f'%{occupations}%')
    
    if support_group is not None:
        query += " AND support_group = %s"
        filters.append(support_group)
    
    if covid_vaccine_date is not None:
        query += " AND covid_vaccine_date = %s"
        filters.append(covid_vaccine_date)
    
    if allergies:
        query += " AND allergies LIKE %s"
        filters.append(f'%{allergies}%')
    
    if media_release is not None:
        query += " AND media_release = %s"
        filters.append(media_release)
    
    if start_date is not None:
        query += " AND start_date = %s"
        filters.append(start_date)
    
    if end_date is not None:
        query += " AND end_date = %s"
        filters.append(end_date)
    
    if robly is not None:
        query += " AND robly = %s"
        filters.append(robly)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_emergency_contact(name='', relationship='', day_phone='', 
                          evening_phone='', cell_phone='', 
                          address='', completion_date=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Emergency_Contact WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if name:
        query += " AND name LIKE %s"
        filters.append(f'%{name}%')
    
    if relationship:
        query += " AND relationship LIKE %s"
        filters.append(f'%{relationship}%')
    
    if day_phone:
        query += " AND day_phone LIKE %s"
        filters.append(f'%{day_phone}%')
    
    if evening_phone:
        query += " AND evening_phone LIKE %s"
        filters.append(f'%{evening_phone}%')
    
    if cell_phone:
        query += " AND cell_phone LIKE %s"
        filters.append(f'%{cell_phone}%')
    
    if address:
        query += " AND address LIKE %s"
        filters.append(f'%{address}%')
    
    if completion_date is not None:
        query += " AND completion_date = %s"
        filters.append(completion_date)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_volunteer(name='', phone='', address='', email='', 
                  background_check_date=None, video_watched_date=None, 
                  media_release=None, confidentiality=None, 
                  training_level=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Volunteer WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if name:
        query += " AND name LIKE %s"
        filters.append(f'%{name}%')
    
    if phone:
        query += " AND phone LIKE %s"
        filters.append(f'%{phone}%')
    
    if address:
        query += " AND address LIKE %s"
        filters.append(f'%{address}%')
    
    if email:
        query += " AND email LIKE %s"
        filters.append(f'%{email}%')
    
    if background_check_date is not None:
        query += " AND background_check_date = %s"
        filters.append(background_check_date)
    
    if video_watched_date is not None:
        query += " AND video_watched_date = %s"
        filters.append(video_watched_date)
    
    if media_release is not None:
        query += " AND media_release = %s"
        filters.append(media_release)
    
    if confidentiality is not None:
        query += " AND confidentiality = %s"
        filters.append(confidentiality)
    
    if training_level is not None:
        query += " AND training_level = %s"
        filters.append(training_level)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_applications(birthday=None, occupation='', is_slp=None, 
                     languages_spoken='', will_substitute=None, 
                     convicted_of_crime=None, application_date=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Applications WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if birthday is not None:
        query += " AND birthday = %s"
        filters.append(birthday)
    
    if occupation:
        query += " AND occupation LIKE %s"
        filters.append(f'%{occupation}%')
    
    if is_slp is not None:
        query += " AND is_slp = %s"
        filters.append(is_slp)
    
    if languages_spoken:
        query += " AND languages_spoken LIKE %s"
        filters.append(f'%{languages_spoken}%')
    
    if will_substitute is not None:
        query += " AND will_substitute = %s"
        filters.append(will_substitute)
    
    if convicted_of_crime is not None:
        query += " AND convicted_of_crime = %s"
        filters.append(convicted_of_crime)
    
    if application_date is not None:
        query += " AND application_date = %s"
        filters.append(application_date)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def get_outreach(contacted_date=None, staff_contacted='', 
                 organization='', org_type='', outreach_type='', 
                 target_location='', num_people=None, robly=None):
    cursor = connection.cursor()
    
    # Start building the base query
    query = "SELECT * FROM Outreach WHERE 1=1"
    filters = []
    
    # Append conditions based on provided arguments
    if contacted_date is not None:
        query += " AND contacted_date = %s"
        filters.append(contacted_date)
    
    if staff_contacted:
        query += " AND staff_contacted LIKE %s"
        filters.append(f'%{staff_contacted}%')
    
    if organization:
        query += " AND organization LIKE %s"
        filters.append(f'%{organization}%')
    
    if org_type:
        query += " AND org_type LIKE %s"
        filters.append(f'%{org_type}%')
    
    if outreach_type:
        query += " AND outreach_type LIKE %s"
        filters.append(f'%{outreach_type}%')
    
    if target_location:
        query += " AND target_location LIKE %s"
        filters.append(f'%{target_location}%')
    
    if num_people is not None:
        query += " AND num_people = %s"
        filters.append(num_people)
    
    if robly is not None:
        query += " AND robly = %s"
        filters.append(robly)
    
    # Execute the query with filters
    cursor.execute(query, tuple(filters))
    
    # Fetch all results
    results = cursor.fetchall()
    
    return results

def update_record(model_name, record_id, updates):
    cursor = connection.cursor()

    # Prepare the base query
    query = f"UPDATE {model_name} SET "
    set_clause = []
    values = []

    # Construct the SET clause from the updates dictionary
    for column, value in updates.items():
        set_clause.append(f"{column} = %s")
        values.append(value)

    # Join the set_clause with commas
    query += ', '.join(set_clause)
    query += " WHERE id = %s"
    values.append(record_id)

    # Execute the query
    cursor.execute(query, tuple(values))

    # Commit the changes to the database
    connection.commit()
    
    # Check if any rows were updated
    if cursor.rowcount == 0:
        print("No record found with the specified ID.")
    
    cursor.close()


# Define your database connection parameters
host = "localhost"
user = "connector"
password = "password"
database = "adler_aphasia_center"

# Establish a connection
connection = create_connection(host, user, password, database)

# Fetch members
members = get_caller(staff_name='Alice')

# Print the fetched data
if members:
    for member in members:
        print(member)

# Close the connection
if connection:
    connection.close()
