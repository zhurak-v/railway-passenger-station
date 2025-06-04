var hierarchy =
[
    [ "Base", "class_base.html", [
      [ "Brigade", "class_brigade.html", [
        [ "LocomotiveBrigade", "class_locomotive_brigade.html", null ],
        [ "TechnicianBrigade", "class_technician_brigade.html", null ]
      ] ],
      [ "Department", "class_department.html", null ],
      [ "Employee", "class_employee.html", [
        [ "Cashier", "class_cashier.html", null ],
        [ "Dispatcher", "class_dispatcher.html", null ],
        [ "Driver", "class_driver.html", null ],
        [ "HeadDepartment", "class_head_department.html", null ],
        [ "Staff", "class_staff.html", null ],
        [ "Technician", "class_technician.html", null ]
      ] ],
      [ "Locomotive", "class_locomotive.html", null ],
      [ "Passenger", "class_passenger.html", null ],
      [ "Route", "class_route.html", null ],
      [ "Station", "class_station.html", null ],
      [ "Ticket", "class_ticket.html", null ],
      [ "Train", "class_train.html", null ],
      [ "Trip", "class_trip.html", null ]
    ] ],
    [ "BaseRelation< A, B >", "class_base_relation.html", [
      [ "ManyToMany< A, B >", "class_many_to_many.html", null ],
      [ "OneToMany< A, B >", "class_one_to_many.html", null ],
      [ "OneToOne< A, B >", "class_one_to_one.html", null ]
    ] ],
    [ "BaseRelation< Department, Employee >", "class_base_relation.html", [
      [ "OneToMany< Department, Employee >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< Department, HeadDepartment >", "class_base_relation.html", [
      [ "OneToOne< Department, HeadDepartment >", "class_one_to_one.html", null ]
    ] ],
    [ "BaseRelation< Locomotive, Driver >", "class_base_relation.html", [
      [ "OneToMany< Locomotive, Driver >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< Locomotive, Trip >", "class_base_relation.html", [
      [ "ManyToMany< Locomotive, Trip >", "class_many_to_many.html", null ]
    ] ],
    [ "BaseRelation< LocomotiveBrigade, Locomotive >", "class_base_relation.html", [
      [ "OneToOne< LocomotiveBrigade, Locomotive >", "class_one_to_one.html", null ]
    ] ],
    [ "BaseRelation< LocomotiveBrigade, Staff >", "class_base_relation.html", [
      [ "OneToMany< LocomotiveBrigade, Staff >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< Route, Station >", "class_base_relation.html", [
      [ "ManyToMany< Route, Station >", "class_many_to_many.html", null ]
    ] ],
    [ "BaseRelation< Route, Trip >", "class_base_relation.html", [
      [ "OneToMany< Route, Trip >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< Station, Locomotive >", "class_base_relation.html", [
      [ "OneToMany< Station, Locomotive >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< TechnicianBrigade, Locomotive >", "class_base_relation.html", [
      [ "OneToMany< TechnicianBrigade, Locomotive >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< TechnicianBrigade, Technician >", "class_base_relation.html", [
      [ "OneToMany< TechnicianBrigade, Technician >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRelation< Train, Locomotive >", "class_base_relation.html", [
      [ "OneToOne< Train, Locomotive >", "class_one_to_one.html", null ]
    ] ],
    [ "BaseRelation< Trip, Ticket >", "class_base_relation.html", [
      [ "OneToMany< Trip, Ticket >", "class_one_to_many.html", null ]
    ] ],
    [ "BaseRepository< T >", "class_base_repository.html", null ],
    [ "BaseRepository< Brigade >", "class_base_repository.html", [
      [ "BrigadeRepository", "class_brigade_repository.html", null ]
    ] ],
    [ "BaseRepository< Cashier >", "class_base_repository.html", [
      [ "CashierRepository", "class_cashier_repository.html", null ]
    ] ],
    [ "BaseRepository< Department >", "class_base_repository.html", [
      [ "DepartmentRepository", "class_department_repository.html", null ]
    ] ],
    [ "BaseRepository< Dispatcher >", "class_base_repository.html", [
      [ "DispatcherRepository", "class_dispatcher_repository.html", null ]
    ] ],
    [ "BaseRepository< Driver >", "class_base_repository.html", [
      [ "DriverRepository", "class_driver_repository.html", null ]
    ] ],
    [ "BaseRepository< Employee >", "class_base_repository.html", [
      [ "EmployeeRepository", "class_employee_repository.html", null ]
    ] ],
    [ "BaseRepository< HeadDepartment >", "class_base_repository.html", [
      [ "HeadDepartmentRepository", "class_head_department_repository.html", null ]
    ] ],
    [ "BaseRepository< Locomotive >", "class_base_repository.html", [
      [ "LocomotiveRepository", "class_locomotive_repository.html", null ]
    ] ],
    [ "BaseRepository< LocomotiveBrigade >", "class_base_repository.html", [
      [ "LocomotiveBrigadeRepository", "class_locomotive_brigade_repository.html", null ]
    ] ],
    [ "BaseRepository< Passenger >", "class_base_repository.html", [
      [ "PassengerRepository", "class_passenger_repository.html", null ]
    ] ],
    [ "BaseRepository< Route >", "class_base_repository.html", [
      [ "RouteRepository", "class_route_repository.html", null ]
    ] ],
    [ "BaseRepository< Staff >", "class_base_repository.html", [
      [ "StaffRepository", "class_staff_repository.html", null ]
    ] ],
    [ "BaseRepository< Station >", "class_base_repository.html", [
      [ "StationRepository", "class_station_repository.html", null ]
    ] ],
    [ "BaseRepository< Technician >", "class_base_repository.html", [
      [ "TechnicianRepository", "class_technician_repository.html", null ]
    ] ],
    [ "BaseRepository< TechnicianBrigade >", "class_base_repository.html", [
      [ "TechnicianBrigadeRepository", "class_technician_brigade_repository.html", null ]
    ] ],
    [ "BaseRepository< Ticket >", "class_base_repository.html", [
      [ "TicketRepository", "class_ticket_repository.html", null ]
    ] ],
    [ "BaseRepository< Train >", "class_base_repository.html", [
      [ "TrainRepository", "class_train_repository.html", null ]
    ] ],
    [ "BaseRepository< Trip >", "class_base_repository.html", [
      [ "TripRepository", "class_trip_repository.html", null ]
    ] ],
    [ "Date", "class_date.html", null ],
    [ "EntitiesBuckets", "struct_entities_buckets.html", null ],
    [ "EntityFactory", "class_entity_factory.html", null ],
    [ "Math", "class_math.html", null ],
    [ "Position", "class_position.html", null ],
    [ "RelationMenu", "class_relation_menu.html", null ],
    [ "RelationServices", "class_relation_services.html", null ],
    [ "TicketStatus", "class_ticket_status.html", null ],
    [ "TripStatus", "class_trip_status.html", null ],
    [ "WeakEqual", "struct_weak_equal.html", null ],
    [ "WeakHash", "struct_weak_hash.html", null ]
];