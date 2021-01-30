import {
    Entity,
    Column,
    PrimaryGeneratedColumn,
    OneToOne,
    JoinColumn,
} from 'typeorm'
import { Business } from './Business'

@Entity()
export class OpeningTimes {
    @PrimaryGeneratedColumn()
    id: number

    // TypeORM, makes it a foreign key in the database table but in the code you create the relationship with a Table Object. TypeORM names this column businessId
    // Unidirectional relationship
    @OneToOne(() => Business)
    business: Business

    @Column()
    monStartTime: string

    @Column()
    monEndTime: string

    @Column()
    tueStartTime: string

    @Column()
    tueEndTime: string

    @Column()
    wedStartTime: string

    @Column()
    wedEndTime: string

    @Column()
    thursStartTime: string

    @Column()
    thursEndTime: string

    @Column()
    friStartTime: string

    @Column()
    friEndTime: string

    @Column()
    satStartTime: string

    @Column()
    satEndTime: string

    @Column()
    sunStartTime: string

    @Column()
    sunEndTime: string
}
