import {
    Entity,
    Column,
    PrimaryGeneratedColumn,
    JoinColumn,
    ManyToOne,
} from 'typeorm'
import { Business } from './Business'
import { User } from './User'

@Entity()
export class Review {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    rating: number

    @Column()
    comment: string

    @ManyToOne(() => User, (user) => user.reviews)
    user: User

    @ManyToOne(() => Business, (business) => business.reviews)
    business: Business
}
