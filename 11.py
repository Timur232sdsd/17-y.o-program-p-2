from datetime import datetime, timedelta

def find_optimal_route(N, flights):
    def convert_to_datetime(time_str):
        return datetime.strptime(time_str, "%H:%M")

    def convert_to_str(time_delta):
        hours, remainder = divmod(time_delta.seconds, 3600)
        minutes, _ = divmod(remainder, 60)
        return "{:02}:{:02}".format(hours, minutes)

    def is_valid_time(current_time, next_flight_time):
        return (next_flight_time - current_time).total_seconds() >= 1.5 * 3600

    # Создаем словарь для хранения информации о рейсах из каждого города
    flights_dict = {}
    for flight in flights:
        departure_city, arrival_city, departure_time_str, travel_time_str = flight.split("|")
        departure_time = convert_to_datetime(departure_time_str)
        travel_time = timedelta(hours=int(travel_time_str.split(":")[0]), minutes=int(travel_time_str.split(":")[1]))

        if departure_city not in flights_dict:
            flights_dict[departure_city] = []

        flights_dict[departure_city].append({
            'arrival_city': arrival_city,
            'departure_time': departure_time,
            'travel_time': travel_time
        })

    # Начинаем поиск оптимального маршрута из Москвы
    current_city = 'Moscow'
    current_time = convert_to_datetime("00:00")
    total_travel_time = timedelta()

    while current_city in flights_dict:
        valid_flights = [flight for flight in flights_dict[current_city] if is_valid_time(current_time, flight['departure_time'])]
        if not valid_flights:
            break

        # Выбираем рейс с самым ранним временем отправления
        next_flight = min(valid_flights, key=lambda x: x['departure_time'])
        current_city = next_flight['arrival_city']
        current_time = next_flight['departure_time'] + next_flight['travel_time']
        total_travel_time += next_flight['travel_time']

    if total_travel_time >= timedelta(hours=12):
        # Если время в пути больше или равно 12 часам, выводим маршрут максимальной длины
        max_route = max(flights_dict.keys(), key=lambda x: len(flights_dict[x]))
        max_travel_time = sum(flight['travel_time'].seconds for flight in flights_dict[max_route], timedelta()).total_seconds()
        print(max_route)
        print(convert_to_str(timedelta(seconds=max_travel_time)))
    else:
        # Иначе выводим оптимальный маршрут
        print(current_city)
        print(convert_to_str(total_travel_time))

# Ввод данных
N = int(input())
flights = [input() for _ in range(N)]

# Поиск оптимального маршрута
find_optimal_route(N, flights)
