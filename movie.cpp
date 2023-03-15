#include "movie.h"

Movie::Movie()
{

}

Movie::Movie(int id, QString name, QString picture)
{
    m_id = id;
    m_name = name;
    m_picture = picture;
}

Movie::Movie(int id, QString name, QString introduce, QString picture, QString directors, QString actors, QString duration, QString type)
{
    m_id = id;
    m_name = name;
    m_introduce = introduce;
    m_picture = picture;
    m_dirtectors = directors;
    m_actors = actors;
    m_duration = duration;
    m_type = type;
}

int Movie::id() const
{
    return m_id;
}

QString Movie::name() const
{
    return m_name;
}

void Movie::setName(const QString &newName)
{
    m_name = newName;
}

QString Movie::introduce() const
{
    return m_introduce;
}

void Movie::setIntroduce(const QString &newIntroduce)
{
    m_introduce = newIntroduce;
}

QString Movie::actors() const
{
    return m_actors;
}

void Movie::setActors(const QString &newActors)
{
    m_actors = newActors;
}

QString Movie::duration() const
{
    return m_duration;
}

void Movie::setDuration(const QString &newDuration)
{
    m_duration = newDuration;
}

QString Movie::type() const
{
    return m_type;
}

void Movie::setType(const QString &newType)
{
    m_type = newType;
}

QString Movie::picture() const
{
    return m_picture;
}

void Movie::setPicture(const QString &newPicture)
{
    m_picture = newPicture;
}

QString Movie::dirtectors() const
{
    return m_dirtectors;
}

void Movie::setDirtectors(const QString &newDirtectors)
{
    m_dirtectors = newDirtectors;
}

Place::Place()
{

}

Place::Place(int id, QString name, int movieId, QString movieName, QDate date, int price, QTime startTime, QTime endTime, int maxRow, int maxCol, QBitArray seat)
{
    m_id = id;
    m_name = name;
    m_movieName = movieName;
    m_movieId = movieId;
    m_date = date;
    m_price = price;
    m_maxRow = maxRow;
    m_maxCol = maxCol;
    m_startTime = startTime;
    m_endTime = endTime;
    m_seat = seat;
}

int Place::id() const
{
    return m_id;
}

QString Place::name() const
{
    return m_name;
}

void Place::setName(QString newName)
{
    m_name = newName;
}

QBitArray Place::seat() const
{
    return m_seat;
}

void Place::setSeat(const QBitArray &newSeat)
{
    m_seat = newSeat;
}

QString Place::movieName() const
{
    return m_movieName;
}

QDate Place::getDate() const
{
    return m_date;
}

void Place::setDate(const QDate &newDate)
{
    m_date = newDate;
}

int Place::price() const
{
    return m_price;
}

void Place::setPrice(int newPrice)
{
    m_price = newPrice;
}

QTime Place::startTime() const
{
    return m_startTime;
}

void Place::setStartTime(const QTime &newStartTime)
{
    m_startTime = newStartTime;
}

QTime Place::endTime() const
{
    return m_endTime;
}

void Place::setEndTime(const QTime &newEndTime)
{
    m_endTime = newEndTime;
}

int Place::maxRow() const
{
    return m_maxRow;
}

void Place::setMaxRow(int newMaxRow)
{
    m_maxRow = newMaxRow;
}

int Place::maxCol() const
{
    return m_maxCol;
}

void Place::setMaxCol(int newMaxCol)
{
    m_maxCol = newMaxCol;
}

int Place::movieId() const
{
    return m_movieId;
}

void Place::setMovieId(int newMovieId)
{
    m_movieId = newMovieId;
}

Ticket::Ticket()
{

}

Ticket::Ticket(int userId, int movieId, QString movieName, int placeId, int row, int col, QDateTime time)
{
    m_userId = userId;
    m_movieId = movieId;
    m_movieName = movieName;
    m_placeId = placeId;
    m_time = time;
    m_row = row;
    m_col = col;
}

Ticket::Ticket(int id, int userId, int movieId, QString movieName, int placeId, int row, int col, QDateTime time)
{
    m_id = id;
    m_userId = userId;
    m_movieId = movieId;
    m_movieName = movieName;
    m_placeId = placeId;
    m_time = time;
    m_row = row;
    m_col = col;
}

int Ticket::userId() const
{
    return m_userId;
}

void Ticket::setUserId(int newUserId)
{
    m_userId = newUserId;
}

int Ticket::movieId() const
{
    return m_movieId;
}

void Ticket::setMovieId(int newMovieId)
{
    m_movieId = newMovieId;
}

int Ticket::placeId() const
{
    return m_placeId;
}

void Ticket::setPlaceId(int newPlaceId)
{
    m_placeId = newPlaceId;
}

QDateTime Ticket::time() const
{
    return m_time;
}

void Ticket::setTime(const QDateTime &newTime)
{
    m_time = newTime;
}

int Ticket::row() const
{
    return m_row;
}

void Ticket::setRow(int newRow)
{
    m_row = newRow;
}

int Ticket::col() const
{
    return m_col;
}

void Ticket::setCol(int newCol)
{
    m_col = newCol;
}

int Ticket::id() const
{
    return m_id;
}

QString Ticket::movieName() const
{
    return m_movieName;
}

void Ticket::setMovieName(const QString &newMovieName)
{
    m_movieName = newMovieName;
}
