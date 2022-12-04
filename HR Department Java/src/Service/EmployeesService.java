package Service;
import Оrganization.Employees;
import Sourse.Repository;

import java.util.List;

public class EmployeesService implements Service<Employees> {

    private final Repository<Employees> repository;

    public EmployeesService(Repository<Employees> repository) {
        this.repository = repository;
    }

    @Override
    public Employees getById(int id) {
        return repository.find(id);
    }

    @Override
    public List<Employees> getAll() {
        return repository.list();
    }

    @Override
    public void save(Employees source) {
        repository.save(source);
    }
}
