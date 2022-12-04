

import Оrganization.Departments;
import Оrganization.Employees;
import Sourse.DBFillingEmployees;
import Sourse.DBFillingRepository;
import Sourse.DBConnector;
import Sourse.Repository;
import Service.DepartmentsService;
import Service.Service;
import view.Component;
import view.ComponentFabric;
import Service.EmployeesService;

import java.util.Scanner;
public class Main {


    public static void main(String[] args)  {
        DBConnector connector = new DBConnector();
        Repository<Departments> repository = new DBFillingRepository();
        Repository<Employees> repository1 = new DBFillingEmployees();
        Service<Departments> service = new DepartmentsService(repository);
        Service<Employees> service1 = new EmployeesService(repository1);
        ComponentFabric fabric = new ComponentFabric();
        System.out.println("----- Enter 0 to see menu ----\n");
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int command = scanner.nextInt();
            Component component = fabric.build(command, service,service1);
            if (component == null) {
                return;
            }
            component.draw();
        }
    }
}
