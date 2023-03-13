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

Movie::Movie(int id, QString name, QString introduce, QString picture, QStringList directors, QStringList actors, QString duration, QStringList type)
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

QStringList Movie::actors() const
{
    return m_actors;
}

void Movie::setActors(const QStringList &newActors)
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

QStringList Movie::type() const
{
    return m_type;
}

void Movie::setType(const QStringList &newType)
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

Place::Place()
{

}

int Place::id() const
{
    return m_id;
}

Ticket::Ticket()
{

}

Ticket::Ticket(int id, int userId, int movieId, int placeId, QTime time, int row, int col)
{
    m_id = id,
    m_userId = userId;
    m_movieId = movieId;
    m_placeId = placeId;
    m_time = time;
    m_row = row;
    m_col = col;
}
