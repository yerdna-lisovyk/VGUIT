package Оrganization;

import java.util.ArrayList;
import java.util.List;

public class Departments {
    private int id;
    private String title;
    private List<Employees> employeesList;

    public Departments(int id,String title,List<Employees> employeesList)
    {
        this.id = id;
        this.title =title;
        this.employeesList = employeesList;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }
    public  List<Employees> getEmployeesList()
    {
        return employeesList;
    }
    @Override
    public String toString() {
        List<String> fio = new ArrayList<>();
        for(int i =0;i<employeesList.size();i++)
        {
            fio.add(employeesList.get(i).getFio());
        }

        return "Department{" +
                "id=" + id +
                ", title ='" + title + '\'' +
                ", employees=" + fio+
                '}';
    }
}
