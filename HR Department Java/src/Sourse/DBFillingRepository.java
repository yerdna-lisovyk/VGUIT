package Sourse;
import Оrganization.Departments;
import Оrganization.Employees;
import Оrganization.Gender;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;


public class DBFillingRepository implements Repository<Departments> {



    private final Mapper<Departments> mapper = resultSet -> {
        int idn = resultSet.getInt("id_department");
        String name = resultSet.getString("title");
        List<Employees> employeesList = new ArrayList<>();
        PreparedStatement pstmt = DBConnector.conn.prepareStatement("SELECT * FROM employees WHERE id_department = ?");
        pstmt.setInt(1,idn);
        ResultSet rs = pstmt.executeQuery();
        while (rs.next())
        {
            employeesList.add(new Employees(rs.getInt("id_employees"),
                    rs.getString("fio"),rs.getInt("age"),
                    Gender.valueOf(rs.getString("gender")),rs.getInt("id_department")));
        }
        return new Departments(idn, name,employeesList);
    };

    @Override
    public Departments find(int id) {
        String query = "select * from departments WHERE id_department = ? ";
        return Optional.of(SqlMetod.executeSelect(query, statement -> statement.setInt(1, id),mapper).get(0))
                .orElseThrow(() -> new RuntimeException("No elements found by given id"));
    }

    @Override
    public void save(Departments source) {
        String insertQuery = "insert into departments (title) values (?)";
        String updateQuery = "update departments set title = ? where id_department = ?";
        int rows;
        if (source.getId() == 0) {
            rows = SqlMetod.execute(insertQuery, statement -> statement.setString(1, source.getTitle()));
        } else {
            rows = SqlMetod.execute(updateQuery, statement -> {
                statement.setString(1, source.getTitle());
                statement.setLong(2, source.getId());
            });
        }
        System.out.println("Rows affected: " + rows);
    }

    @Override
    public void remove(Departments target) {
        String query = "delete from departments where id_department = ?";
        int rows = SqlMetod.execute(query, statement -> statement.setLong(1, target.getId()));
        System.out.println("Rows affected: " + rows);
    }

    @Override
    public List<Departments> list() {
        String query = "select * from departments";
        return SqlMetod.executeSelect(query, null, mapper);
    }



}
