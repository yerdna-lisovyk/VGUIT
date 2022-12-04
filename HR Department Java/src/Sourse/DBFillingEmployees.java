package Sourse;

import Оrganization.Employees;
import Оrganization.Gender;

import java.util.List;
import java.util.Optional;



public class DBFillingEmployees implements Repository<Employees> {
    private final Mapper<Employees> mapper = resultSet ->{

        int idn = resultSet.getInt("id_employees");
        String fio = resultSet.getString("fio");
        int age = resultSet.getInt("age");
        Gender gender = Gender.valueOf(resultSet.getString("gender"));
        int id_dep = resultSet.getInt("id_department");
        return new Employees(idn,fio,age,gender,id_dep);
    };

    @Override
    public Employees find(int id) {
        String query = "select * from employees where id_employees = ?";
        return Optional.of(SqlMetod.executeSelect(query, statement -> statement.setInt(1, id),mapper).get(0))
                .orElseThrow(() -> new RuntimeException("No elements found by given id"));
    }

    @Override
    public void save(Employees source) {
        String insertQuery = "insert into employees (fio,age,gender,id_department) values (?,?,?,?)";
        String updateQuery = "update employees set fio = ? , age = ? , gender = ?   where id_employees = ?";
        int rows;
        if (source.getId() == 0) {
            rows = SqlMetod.execute(insertQuery, statement -> {
                    statement.setString(1, source.getFio());
                    statement.setInt(2, source.getAge());
                    statement.setString(3, source.getGender().toString());
                    statement.setInt(4, source.getId_depart());
            });
        } else {
            rows = SqlMetod.execute(updateQuery, statement -> {
                statement.setString(1, source.getFio());
                statement.setInt(2, source.getAge());
                statement.setString(3, source.getGender().getText());
                statement.setInt(4, source.getId_depart());
            });
        }
        System.out.println("Rows affected: " + rows);
    }

    @Override
    public void remove(Employees target) {
        String query = "delete from employees where id_employees = ?";
        int rows = SqlMetod.execute(query, statement -> statement.setLong(1, target.getId()));
        System.out.println("Rows affected: " + rows);
    }

    @Override
    public List<Employees> list() {
        String query = "select * from employees";
        return SqlMetod.executeSelect(query, null, mapper);
    }
}
