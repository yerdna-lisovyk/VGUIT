package Sourse;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import static Sourse.DBConnector.conn;

public class SqlMetod {
    public static <T> List<T> executeSelect(String query, SQLStatementConsumer consumer, Mapper<T> mapper)
    {
        try (
                PreparedStatement statement = conn.prepareStatement(query);
        ) {
            if (consumer != null ) {
                consumer.accept(statement);
            }
            ResultSet resultSet = statement.executeQuery();
            List<T> depart = new ArrayList<>();
            while (resultSet.next()) {

                T box = mapper.map(resultSet);
                depart.add(box);
            }
            return depart;
        } catch (SQLException e) {
            throw new RuntimeException("Error while Repository::list method executing: " + e);
        }
    }
    public static int execute(String query, SQLStatementConsumer consumer) {
        try (
                PreparedStatement statement = conn.prepareStatement(query)
        ) {
            consumer.accept(statement);
            return statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException("Error while Repository::save method executing: " + e);
        }
    }
}
